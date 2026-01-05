/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/04 19:34:23 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}

int	sort_complete(t_list *list, size_t original_size)
{
	t_list			*lst;
	unsigned int	in;

	lst = list;
	in = 0;
	while (lst)
	{
		if (lst->next != NULL && lst->content > lst->next->content)
			return (0);
		lst = lst->next;
		in++;
	}
	if (in < original_size)
		return (0);
	return (1);
}

unsigned int	times_smaller(t_list *list)
{
	unsigned int	amount;
	t_list			*lst;

	lst = list;
	while (lst)
	{
		if (lst->content < lst->next->content)
			amount++;
		else
			return (amount);
		lst = lst->next;
	}
	return (amount);
}

unsigned int	times_greater(t_list *list)
{
	unsigned int	amount;
	t_list			*lst;

	lst = list;
	while (lst)
	{
		if (lst->content > lst->next->content)
			amount++;
		else
			return (amount);
		lst = lst->next;
	}
	return (amount);
}

void	display_list(t_list *list)
{
	t_list	*lst;

	lst = list;
	ft_printf("========== Displaying list ==========\n");
	while (lst)
	{
		ft_printf("%u\n", lst->content);
		lst = lst->next;
	}
	ft_printf("=====================================\n");
	ft_printf("========= This list contains %d items\n\n", ft_lstsize(list));
}
