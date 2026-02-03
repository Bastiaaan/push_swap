/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:00:33 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/03 18:07:56 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimal_place(t_list *a, t_list *b)
{
	t_list	*la;
	t_list	*lb;
	int		gap_init;
	int		gap_current;

	la = a;
	lb = b;
	gap_current = 0;
	gap_init = 0;
	while (la)
	{
		if (gap_init != NULL && lb->content < la->content)
			gap_current = (la->content - lb->content);
		else if (lb->content < la->content)
			gap_init = (la->content - lb->content);
		la = la->next;
	}
	if (gap_init < gap_current || gap_current == 0)
		return (1);
	return (0);
}

int	ascending(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->next != NULL && lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	exceed_largest(t_list *list, t_list *item)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->content > item->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	exceed_smallest(t_list *list, t_list *item)
{
	t_list	*lst;
	t_list	*cpy;

	lst = list;
	cpy = item;
	while (lst)
	{
		if (lst->content < cpy->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
