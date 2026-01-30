/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 18:15:08 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_route(t_list **a, t_list **b, t_route route)
{
	while (route.steps--)
	{
		if (route.direction > 0)
			ra(a);
		else
			rra(a);
	}
	while (route.self_steps--)
	{
		if (route.self_direction > 0)
			rb(b);
		else
			rrb(b);
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_instructions	intr_min(t_instructions *a, t_instructions *b)
{
	if ((a->rot_a + a->rot_b + a->rev_a + a->rev_b + a->rr + a->rrr)
		< (b->rot_a + b->rot_b + b->rev_a + b->rev_b + b->rr + b->rrr))
		return (*a);
	return (*b);
}

t_route	get_shortest(t_route *route_1, t_route *route_2)
{
	if ((route_1->steps + route_1->self_steps)
		< (route_2->steps + route_2->self_steps))
		return (*route_1);
	return (*route_2);
}

t_instructions init(int rot_a, int rot_b, int rev_a, int rev_b, int rr, int rrr)
{
	t_instructions	new;

	new.rot_a = rot_a;
	new.rot_b = rot_b;
	new.rev_a = rev_a;
	new.rev_b = rev_b;
	new.rr = rr;
	new.rrr = rrr;
	return (new);
}

t_instructions	calc_cost(int moves_a, int moves_b, size_t s_a, size_t s_b)
{
	t_instructions	instruction;
	int				rev_a;
	int				rev_b;
	int				rr;
	int				rrr;

	rev_a = s_a - moves_a;
	rev_b = s_b - moves_b;
	rr = min(moves_a, moves_b);
	rrr = min((s_a - moves_a), (s_b - moves_b));

	int cost = (moves_a + moves_b) - rr;
	instruction = init(moves_a - rr, moves_b - rr, 0, 0, rr, 0);
	if (cost > (rev_a + rev_b - rrr))
	{
		instruction = init(0, 0, rev_a - rrr, rev_b - rrr, 0, rrr);
		cost = (rev_a + rev_b - rrr);
	}
	if (cost > moves_a + rev_b)
	{
		instruction = init(moves_a, 0, 0, rev_b, 0, 0);
		cost = moves_a + rev_b;
	}
	if (cost > rev_a + moves_b)
	{
		instruction = init(0, moves_b, rev_a, 0, 0, 0);
		cost = rev_a + moves_b;
	}
	return (instruction);
}

static t_instructions	cheapest(t_list **a, t_list **b)
{
	t_list			*lstb;
	t_list			*lsta;
	t_instructions	best;
	t_instructions	curr;
	int				moves_a;
	int				moves_b;

	lstb = *b;
	lsta = *a;
	best = init(999999, 999999, 999999, 999999, 999999, 999999);
	moves_a = 0;
	moves_b = 0;
	while (lstb)
	{
		moves_a = 0;
		while (lsta && lsta->content < lstb->content)
		{
			moves_a++;
			lsta = lsta->next;
		}
		curr = calc_cost(moves_a, moves_b, ft_lstsize(*a), ft_lstsize(*b));
		best = intr_min(&best, &curr);
		moves_b++;
		lsta = *a;
		lstb = lstb->next;
	}
	return (best);
}

static t_route	find_best_option(t_list **a, t_list **b)
{
	t_list	*la;
	t_list	*lb;
	t_route	route;
	t_route	better;
	int		moves_a;
	int		moves_b;

	la = *a;
	lb = *b;
	moves_a = 0;
	moves_b = 0;
	while (lb)
	{
		while (la && la->content < lb->content)
		{
			la = la->next;
			moves_a++;
		}
		route = set_route(lb, la, moves_a, moves_b);
		better = get_shortest(&better, &route);
		moves_b++;
		la = *a;
		lb = lb->next;
	}
	return (better);
}

void	sort_stack(t_list *a, t_list *b, size_t size)
{
	t_route	route;

	while (ft_lstsize(b) > 0)
	{
		route = find_best_option(&a, &b);
		execute_route(&a, &b, route);
		pa(&a, &b);
	}
}
// while (b not empty)
//  calc_instruct
//  execute_instr

//TODO: assign correct values to their correct targets.
//During the iteration, calculate if (b->content < a->content).


// in another function, the t_instructions shall be applied untill all the numbers are set to 0.