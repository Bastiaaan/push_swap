/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_calcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:34:48 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/22 15:53:20 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns -1 for rev_rotate and 1 for rotate for descending operations
int	calc_direction_pb(t_list *list, t_list *item)
{
	int		direction;
	int		matches;
	t_list	*lst;

	lst = clone(list);
	direction = 0;
	matches = 0;
	while (item->content < lst->content
		|| item->content > ft_lstlast(lst)->content)
	{
		rotate(&lst);
		matches++;
	}
	free_list(lst);
	if (matches > (int)(ft_lstsize(list) / 2))
		direction = -1;
	else
		direction = 1;
	return (direction);
}

int	calc_steps_pb(t_list *b, t_list *src)
{
	t_list	*lst;
	int		steps;

	lst = clone(b);
	if (!lst)
		return (NULL);
	if (exceed_smallest(lst, src) || exceed_largest(lst, src))
		steps = calc_exceed_pb(lst);
	else if (ft_lstsize(lst) >= 3)
	{
		steps = 0;
		while (src->content < lst->content
			|| src->content > ft_lstlast(lst)->content)
		{
			if (calc_direction_pb(lst, src) > 0)
				rotate(&lst);
			else
				rev_rotate(&lst);
			steps++;
		}
	}
	free_list(lst);
	return (steps);
}

int	calc_direction_rotate_a(t_list *a)
{
	t_list	*lst;
	int		matches;

	lst = clone(a);
	while (lst->next != NULL)
	{
		if (lst->content < lst->next->content)
			matches++;
		lst = lst->next;
	}
	free_list(lst);
	if (matches > ((int)ft_lstsize(a) / 2))
		return (-1);
	else
		return (1);
}

// original calc_direction_code below;
/*

*/