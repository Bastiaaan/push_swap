/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:58:57 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/28 13:59:36 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcontains(t_list **list, t_list *item)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
		if (lst->content == item->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}
