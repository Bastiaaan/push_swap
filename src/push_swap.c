/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:48:32 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/07 02:31:40 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*lst;
	t_list	*frst;
	t_list	*scnd;

	lst = *list;
	frst = lst;
	scnd = lst->next;
	lst = lst->next->next;
	scnd->next = frst;
	frst->next = lst;
	*list = scnd;
}

void	push(t_list **dest, t_list **src)
{
	t_list	*destlst;
	t_list	*srclst;
	t_list	*firstsrc;

	destlst = *dest;
	srclst = *src;
	firstsrc = srclst;
	*src = srclst->next;
	firstsrc->next = NULL;
	if (destlst->content != NULL)
		ft_lstadd_front(&destlst, firstsrc);
	else
		destlst = firstsrc;
	*dest = destlst;
}

void	rotate(t_list **list)
{
	t_list	*lst;
	t_list	*first;
	t_list	*second;

	lst = *list;
	first = lst;
	second = first->next;
	while (lst->next)
		lst = lst->next;
	first->next = NULL;
	lst->next = first;
	*list = second;
}

void	rev_rotate(t_list **list)
{
	t_list	*lst;
	t_list	*last;
	t_list	*second_last;

	lst = *list;
	last = lst;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = lst;
	*list = last;
}

void	run(t_list *a, t_list *b)
{
	int				lstsize;

	lstsize = ft_lstsize(a);
	sort_list(a, b, lstsize);
}
