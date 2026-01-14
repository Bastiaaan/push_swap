/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_calcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:34:48 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/14 19:16:43 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns -1 for rev_rotate and 1 for rotate for descending operations
int	calc_direction(t_list *list, t_list *item)
{
	int		direction;
	int		matches;
	t_list	*lst;

	lst = list;
	direction = 0;
	matches = 0;
	while (lst && direction == 0)
	{
		if (item->content > lst->content)
		{
			matches++;
			lst = lst->next;
		}
		else
		{
			if (matches >= (int)(ft_lstsize(list) / 2))
				direction = -1;
			else
				direction = 1;
		}
	}
	return (direction);
}

int	calc_steps_pb(t_list *b, t_list *src)
{
	t_list	*lst;
	int		steps;

	lst = b;
	if (!lst)
		return (NULL);
	if (exceed_smallest(b, src) || exceed_largest(b, src))
		return (calc_exceed_pb(b));
	else if (ft_lstsize(lst) >= 3)
	{
		steps = 0;
		while (src->content < lst->content
			|| src->content > ft_lstlast(lst)->content)
		{
			if (src->content < lst->content)
				rotate(&lst);
			else
				rev_rotate(&lst);
			steps++;
		}
	}
	return (steps);
}

int	calc_steps_pa(t_list *a, t_list *src)
{
	return (0);
}

t_list	*cheapest_node_pb(t_list *dest, t_list *src)
{
	t_list	*second;
	t_list	*last;

	second = src->next;
	last = ft_lstlast(src);
	if (calc_steps_pb(dest, src) < calc_steps_pb(dest, second)
		&& calc_steps_pb(dest, src) < calc_steps_pb(dest, last))
		return (src);
	else if (calc_steps_pb(dest, second) < calc_steps_pb(dest, src)
		&& calc_steps_pb(dest, second) < calc_steps_pb(dest, last))
		return (second);
	else if (calc_steps_pb(dest, last) < calc_steps_pb(dest, src)
		&& calc_steps_pb(dest, last) < calc_steps_pb(dest, second))
		return (last);
}
