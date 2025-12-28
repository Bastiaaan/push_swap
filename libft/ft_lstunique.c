/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:59:07 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/28 13:59:12 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstunique(t_list **list)
{
	t_list	*lst;

	lst = *list;
	while (lst)
	{
		if (ft_lstcontains(list, lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}
