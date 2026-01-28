/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:59:07 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/26 17:53:51 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstunique(t_list **list)
{
	t_list	*lst;
	t_list	*cpy;
	int		matches;

	lst = *list;
	matches = 0;
	while (lst)
	{		
		cpy = lst;
		while (cpy)
		{
			if (cpy->content == lst->content)
				matches++;
			if (matches > 1)
				return (0);
			cpy = cpy->next;
		}
		lst = lst->next;
		matches = 0;
	}
	return (1);
}
