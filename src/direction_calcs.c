/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_calcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:34:48 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 06:03:27 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns -1 for rev_rotate and 1 for rotate for descending operations
int	calc_direction_pa(t_list *a, t_list *item)
{
	int		direction;
	int		matches;
	t_list	*lst;

	if (exceed_largest(a, item) || exceed_smallest(a, item))
		direction = calc_direction_exceed(a);
	else
	{
		lst = clone(a);
		matches = 0;
		while (item->content > lst->content
			|| item->content < ft_lstlast(lst)->content)
		{
			rotate(&lst);
			matches++;
		}
		free_list(lst);
		if (matches > (int)(ft_lstsize(a) / 2))
			direction = -1;
		else
			direction = 1;
	}
	return (direction);
}

int	calc_steps_pa(t_list *a, t_list *src)
{
	t_list	*lst;
	int		steps;

	lst = clone(a);
	if (!lst)
		return (NULL);
	else if (exceed_largest(lst, src) || exceed_smallest(lst, src))
		steps = calc_exceed_pa(lst);
	else
	{
		steps = 0;
		while (src->content > lst->content
			|| src->content < ft_lstlast(lst)->content)
		{
			if (calc_direction_pa(lst, src) > 0)
				rotate(&lst);
			else
				rev_rotate(&lst);
			steps++;
		}
	}
	free_list(lst);
	return (steps);
}
