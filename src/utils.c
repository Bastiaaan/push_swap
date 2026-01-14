/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/14 18:45:13 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
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

void	display_list(t_list *list)
{
	t_list	*lst;

	lst = list;
	ft_printf("========== Displaying list ==========\n");
	while (lst)
	{
		ft_printf("value: %u\n", lst->content);
		ft_printf("rank: %d\n", lst->rank);
		lst = lst->next;
	}
	ft_printf("=====================================\n");
	ft_printf("========= This list contains %d items\n\n", ft_lstsize(list));
}
