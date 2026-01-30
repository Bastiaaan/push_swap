/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_calcs1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:50:04 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 06:17:02 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 for rotate. returns -1 for reverse rotate
int	calc_direction_exceed(t_list *list)
{
	t_list	*lst;
	t_list	*prev;
	int		steps;

	steps = 0;
	lst = list;
	while (lst)
	{
		prev = lst;
		lst = lst->next;
		if (lst != NULL && lst->content < prev->content)
		{
			if (steps < ((int)ft_lstsize(lst) / 2))
				return (1);
			else
				return (-1);
		}
		steps++;
	}
	return (0);
}

int	calc_exceed_pa(t_list *a)
{
	t_list	*lst;
	int		steps;

	steps = 0;
	if (ascending(a))
		return (steps++);
	else
	{
		lst = clone(a);
		while (!ascending(lst))
		{
			if (calc_direction_exceed(lst) < 0)
				rev_rotate(&lst);
			else
				rotate(&lst);
			steps++;
		}
		free_list(lst);
	}
	return (steps);
}
