/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/19 17:37:48 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_fit(t_list *b, t_list *node)
{
	return (node != NULL
		&& node->content > b->content
		&& node->content < ft_lstlast(b)->content);
}

t_list	*clone(t_list *src)
{
	t_list	*new;
	t_list	*dest;
	t_list	*lst;

	lst = src;
	dest = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content);
		new->rank = lst->rank;
		if (dest == NULL)
			dest = new;
		else
			ft_lstadd_back(&dest, new);
		lst = lst->next;
	}
	return (dest);
}

void	free_list(t_list *list)
{
	t_list	*lst;
	t_list	*tmp;

	lst = list;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
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
