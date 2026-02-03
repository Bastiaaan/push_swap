/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/03 21:40:02 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_direction(t_list *list)
{
	t_list	*lst;
	int		matches;

	lst = list;
	matches = 0;
	while (lst != NULL)
	{
		if (lst->next != NULL
			&& lst->content < lst->next->content)
			matches++;
		else
			break ;
		lst = lst->next;
	}
	if (matches < (ft_lstsize(list) / 2))
		return (1);
	return (-1);
}

void	finalize(t_list **a)
{
	int	direction;

	direction = get_direction((*a));
	while (!ascending(*a))
	{
		if (direction > 0)
			ra(a);
		else
			rra(a);
	}
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
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
