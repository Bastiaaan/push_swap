/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/07 04:36:04 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function defines the fundamental moves of stack A. 
void	sort_list(t_list *a, t_list *b, size_t size)
{
	if (ft_lstsize(a) >= 2 && ft_lstsize(b) >= 2)
	{
		if ((ft_lstlast(a)->content < a->content
				&& ft_lstlast(a)->content < a->next->content)
			&& (ft_lstlast(b)->content > b->content
				&& ft_lstlast(b)->content > b->next->content))
			rrr(&a, &b);
		if ((a->content > ft_lstlast(a)->content
				&& a->next->content < ft_lstlast(a)->content)
			&& (b->content < ft_lstlast(b)->content
				&& b->next->content > ft_lstlast(b)->content))
			rr(&a, &b);
		if ((a->content > a->next->content)
			&& (b->next->content > b->content))
			ss(&a, &b);
	}
	if (!sort_complete(a, size))
		sort_a(a, b, size);
}

// here whenever stack A is ready to push to stack B, 
void	sort_a(t_list *a, t_list *b, size_t size)
{
	if (ft_lstsize(a) >= 2 && !ascending(a))
	{
		if (ft_lstlast(a)->content < a->content
			&& ft_lstlast(a)->content < a->next->content)
			rra(&a);
		else if (a->content > a->next->content
			&& a->content > ft_lstlast(a)->content)
			ra(&a);
		else if (a->next->content < a->content
			&& a->content < ft_lstlast(a)->content)
			sa(&a);
	}
	if (ascending(a) && !sort_complete(a, size))
	{
		finalize(a, b, size);
		return ;
	}
	if (!sort_complete(a, size))
		sort_b(a, b, size);
}

void	sort_b(t_list *a, t_list *b, size_t size)
{
	int	direction;

	if (ft_lstsize(a) >= 1 && a->content < a->next->content
		&& a->content < ft_lstlast(a)->content && !ascending(a))
	{
		if (ft_lstsize(b) >= 3 && a->content < b->content
			&& !exceed_smallest(b, a))
		{
			direction = short_direction_desc(b, a);
			while (a->content < b->content
				|| a->content > ft_lstlast(b)->content)
			{
				if (direction < 0)
					rrb(&b);
				else
					rb(&b);
			}
		}
		if (a->content > b->content && a->content < ft_lstlast(b)->content
			|| ft_lstsize(b) <= 2 || exceed_smallest(b, a)
			|| exceed_largest(b, a))
			pb(&b, &a);
	}
	if (!sort_complete(a, size))
		sort_list(a, b, size);
}

void	finalize(t_list *a, t_list *b, size_t size)
{
	while (!sort_complete(a, size))
	{
		if (ft_lstsize(b) >= 1)
		{
			if (ft_lstlast(a)->content < a->content
				&& ft_lstlast(a)->content > b->content)
				rra(&a);
			else if (b->content > a->content)
				ra(&a);
			else
				pa(&a, &b);
		}
		else
			if (ft_lstlast(a)->content < a->content
				|| exceed_smallest(a, ft_lstlast(a)))
				rra(&a);
	}
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