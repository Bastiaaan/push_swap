/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/27 17:42:14 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*cheapest(t_list *a, t_list *b)
{
	t_list	*cheapest;
	int		steps_first;
	int		steps_second;
	int		steps_last;

	steps_first = calc_steps_pb(b, a);
	steps_second = calc_steps_pb(b, a->next);
	steps_last = calc_steps_pb(b, ft_lstlast(a));
	if (ft_lstsize(b) >= 2)
	{
		if (steps_first <= steps_second && steps_first <= steps_last)
			cheapest = a;
		else if (steps_second <= steps_first && steps_second <= steps_last)
			cheapest = a->next;
		else if (steps_last <= steps_first && steps_last <= steps_first)
			cheapest = ft_lstlast(a);
	}
	else
		cheapest = NULL;
	return (cheapest);
}

static void	prep_pb(t_list **a, t_list **b, t_list *c, int direction)
{
	int	steps;

	steps = calc_steps_pb(*b, c);
	while (steps > 0)
	{
		if (direction > 0)
		{
			if (steps == 1
				&& (*a)->next->content == c->content
				&& (*a)->next->content > (*b)->next->content)
				rr(a, b);
			else
				rb(b);
		}
		else
		{
			if (steps == 1
				&& ft_lstlast(*a)->content > ft_lstlast(*b)->content
				&& ft_lstlast(*a)->content == c->content)
				rrr(a, b);
			else
				rrb(b);
		}
		steps--;
	}
}

static void	choose_cheapest(t_list *a, t_list *b, size_t size)
{
	int		direction;
	t_list	*chosen;

	if (ft_lstsize(b) >= 2)
	{
		chosen = cheapest(a, b);
		if (exceed_largest(b, chosen) || exceed_smallest(b, chosen))
			direction = calc_direction_exceed(b);
		else
			direction = calc_direction_pb(b, chosen);
		prep_pb(&a, &b, chosen, direction);
	}
	correct_stack(&a, &b, chosen);
	if ((ft_lstsize(b) >= 2 && a->content > b->content
			&& a->content < ft_lstlast(b)->content)
		|| ft_lstsize(b) < 2 || (descending(b) && exceed_smallest(b, a)
			|| exceed_largest(b, a)))
		pb(&b, &a);
	if (!sort_complete(a, size))
		sort_stack(a, b, size);
}

static void	finalize(t_list *a, t_list *b, size_t size)
{
	int	direction;

	direction = calc_direction_rotate_a(a);
	while (!sort_complete(a, size))
	{
		if (ft_lstsize(b) == 0)
		{
			if (direction < 0)
				rra(&a);
			else
				ra(&a);
		}
		else
		{
			if (a->content > ft_lstlast(a)->content
				&& ft_lstlast(a)->content > b->content)
				rra(&a);
			else if (b->content > a->content && a->next->content > b->content)
				sa(&a);
			else
				pa(&a, &b);
		}
	}
}

void	sort_stack(t_list *a, t_list *b, size_t size)
{
	if (ft_lstsize(a) <= 10)
	{
		mini_sort(a, b);
		if (!sort_complete(a, size))
			finalize(a, b, size);
	}
	else if (!sort_complete(a, size))
		choose_cheapest(a, b, size);
}

	/*
	=================== Rotate ===================
	
	execute ra when first is larger than second and second is smaller than last
	execute rb when first is smaller than second and second is larger than last
	
	=============== Reverse Rotate ===============
	
	execute rra when first is larger than last and smaller than second
	execute rrb when first is smaller than last and larger than second.
	
	==================== Swap ====================
	
	execute sa when second is smaller than first and both are smaller than last
	execute sb when second is larger than first and both are larger than last

	==================== Push ====================

	execute pb when first is either smaller than second and smaller than last
	execute pa when first is either larger than second and larger than last 
	ONLY when list a is sorted in an ascending order	
	*/