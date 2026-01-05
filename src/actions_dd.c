/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_dd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:59:58 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/05 06:16:40 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rev_rotate(list_a);
	rev_rotate(list_b);
	ft_printf("rrr\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
