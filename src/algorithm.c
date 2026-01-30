/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 12:50:18 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_instructions intr_min(t_instructions* a, t_instructions* b)
{
	if ((a->rot_a + a->rot_b + a->rev_a + a->rev_b + a->rr + a->rrr) 
		< b->rot_a + b->rot_b + b->rev_a + b->rev_b + b->rr + b->rrr)
		return *a;
	return *b;
}

t_instructions init(int rot_a, int rot_b, int rev_a, int rev_b, int rr, int rrr)
{
	return (t_instructions){
		NULL,
		NULL,
		rot_a,
		rot_b,
		rev_a,
		rev_b,
		rr,
		rrr
	};
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
	return instruction;
}

static t_list	*cheapest(t_list *a, t_list *b)
{
	t_list	*lstb;
	t_list	*lsta;
	t_instructions best;
	t_instructions curr;
	int		moves_a;
	int		moves_b;

	lstb = b;
	lsta = a;
	best = init(999999, 999999, 999999, 999999, 999999, 999999);
	moves_a = 0;
	moves_b = 0;
	while (lstb)
	{
		moves_a = 0;
		while (lsta && lsta->content > lstb->content)
		{
			moves_a++;
			lsta = lsta->next;
		}
		
		curr = calc_cost(moves_a, moves_b, ft_lstsize(a), ft_lstsize(b));
		best = intr_min(&best, &curr);

		lsta = a;
		moves_b++;
		lstb = lstb->next;
	}
	return best;
}

int	total_cost(t_list *a, t_list *b, t_list *node)
{
	int	total;

	total = 0;
	return (0);
}

static void	prep_pa(t_list **a, t_list **b, t_list *c, int direction)
{
	int	steps;

	steps = calc_steps_pa(*a, c);
	while (steps > 0)
	{
		if (direction > 0)
		{
			if (steps == 1
				&& (*b)->next->content == c->content
				&& (*b)->next->content < (*a)->next->content)
				rr(a, b);
			else
				ra(a);
		}
		else
		{
			if (steps == 1
				&& ft_lstlast(*a)->content > ft_lstlast(*b)->content
				&& ft_lstlast(*b)->content == c->content)
				rrr(a, b);
			else
				rra(a);
		}
		steps--;
	}
}

static void	choose_cheapest(t_list *a, t_list *b, size_t size)
{
	int		direction;
	int		steps;
	t_list	*chosen;

	chosen = cheapest(a, b);
	steps = calc_steps_pa(a, chosen);
	if (ft_lstsize(a) >= 40 && steps > (ft_lstsize(a) / 4))
		re_roll(&a, &b, chosen);
	else
	{
		prep_pa(&a, &b, chosen, direction);
		correct_stack(&a, &b, chosen);
		if ((b->content < a->content
				&& b->content > ft_lstlast(a)->content)
			|| (ascending(a) && exceed_largest(a, chosen)
				|| exceed_smallest(a, chosen)))
			pa(&a, &b);
	}
	if (!sort_complete(a, size))
		sort_stack(a, b, size);
}

void	sort_stack(t_list *a, t_list *b, size_t size)
{

	// while (b not empty)
	//  calc_instruct
	//  execute_instr

	int	direction;

	if (ft_lstsize(b) == 1)
	{
		direction = calc_direction_pa(a, b);
		while (b->content > a->content
			|| b->content < ft_lstlast(a)->content)
		{
			if (direction > 0)
				ra(&a);
			else
				rra(&a);
		}
		pa(&a, &b);
		direction = calc_direction_exceed(a);
		while (!sort_complete(a, size))
		{
			if (direction > 0)
				ra(&a);
			else
				rra(&a);
		}
	}
	else if (!sort_complete(a, size))
		choose_cheapest(a, b, size);
}


//TODO: assign correct values to their correct targets.
//During the iteration, calculate if (b->content < a->content).


// in another function, the t_instructions shall be applied untill all the numbers are set to 0.