/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/14 17:48:43 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prepare_position(t_list *a, t_list *b, size_t size)
{
	int	steps;
	int	direction;

	if (ft_lstsize(b) >= 3)
	{
		ft_printf("pls: %u\n", cheapest_node_pb(b, a)->rank);
		return ;
		if (calc_steps_pb(b, a) <= calc_steps_pb(b, a->next)
			&& calc_steps_pb(b, a) <= calc_steps_pb(b, ft_lstlast(a)))
		{
			steps = calc_steps_pb(b, a);
			direction = calc_direction(b, a);
			ft_printf("test %d\n", steps);
			while (steps > 0)
			{
				if (direction > 0)
					rb(&b);
				else
					rrb(&b);
			}
		}
	}
	if (!sort_complete(a, size))
		sort_list(a, b, size);
}

static void	position_next(t_list *a, t_list *b, size_t size)
{
	if (!exceed_largest(b, a) && !exceed_smallest(b, a)
		&& !exceed_largest(b, a->next) && !exceed_smallest(b, a->next)
		&& !exceed_largest(b, a) && !exceed_smallest(b, a))
		prepare_position(a, b, size);
	if (!sort_complete(a, size))
		prepare_position(a, b, size);
}

static void	finalize(t_list *a, t_list *b, size_t size)
{

}

void	sort_list(t_list *a, t_list *b, size_t size)
{
	if (ft_lstsize(b) >= 2)
	{
		if (a->next->content > b->content
			&& a->next->content < ft_lstlast(b)->content)
			sa(&a);
		else if (ft_lstlast(a) > b->content
			&& ft_lstlast(a) < ft_lstlast(b)->content)
			rra(&a);
	}
	if ((a->content > b->content && a->content < ft_lstlast(b)->content)
		|| ft_lstsize(b) < 2 || descending(b) && (exceed_smallest(b, a)
			|| exceed_largest(b, a)))
		pb(&b, &a);
	if (ascending(a))
		finalize(a, b, size);
	if (!sort_complete(a, size))
		position_next(a, b, size);
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