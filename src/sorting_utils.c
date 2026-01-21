/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:00:33 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/21 14:27:26 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	descending(t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (lst->next != NULL && lst->content < lst->next->content)
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
