/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:48:32 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/19 10:16:18 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*fst;
	t_list	*snd;

	fst = *list;
	*list = fst->next;
	snd = *list;
	*list = snd->next;
	ft_lstadd_front(list, fst);
	ft_lstadd_front(list, snd);
}

void	push(t_list **dest, t_list **src)
{
	t_list	*destlst;
	t_list	*srclst;
	t_list	*first;

	destlst = *dest;
	srclst = *src;
	first = srclst;
	*src = srclst->next;
	destlst = first;
	if (ft_lstsize(*dest) > 1)
		ft_lstadd_front(&destlst, first);
	else
		destlst->next = NULL;
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

void	push_swap(t_list *list_a)
{
	t_list	*list_b;
	size_t	capacity;

	capacity = ft_lstsize(list_a);
	list_b = ft_calloc(capacity, sizeof(t_list));
	push(&list_b, &list_a);
	ft_printf("\nDisplaying about stack A\n\n");
	display_list(list_a);
	ft_printf("\nDisplaying about stack B\n\n");
	display_list(list_b);
}

// having directions of: sa sb ss pa pb ra rb rr rra rrb rrr 