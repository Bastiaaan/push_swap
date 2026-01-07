/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/07 02:12:43 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns -1 for rev_rotate and 1 for rotate
int	short_direction_desc(t_list *list, t_list *item)
{
	int		direction;
	int		matches;
	t_list	*lst;

	lst = list;
	direction = 0;
	matches = 0;
	while (lst && direction == 0)
	{
		if (item->content < lst->next->content)
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

int	short_direction_asc(t_list *list, t_list *item)
{
	int		direction;
	int		matches;
	t_list	*lst;

	lst = list;
	direction = 0;
	matches = 0;
	while (lst && direction == 0)
	{
		if (item->content > lst->next->content)
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
		ft_printf("%u\n", lst->content);
		lst = lst->next;
	}
	ft_printf("=====================================\n");
	ft_printf("========= This list contains %d items\n\n", ft_lstsize(list));
}
