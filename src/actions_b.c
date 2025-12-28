/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:00:08 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/28 14:00:10 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **list_b, t_list **list_a)
{
	push(list_b, list_a);
	ft_printf("pb\n");
}

void	rb(t_list **list_b)
{
	rotate(list_b);
	ft_printf("rb\n");
}

void	rrb(t_list **list_b)
{
	rev_rotate(list_b);
	ft_printf("rrb\n");
}

void	sb(t_list **list_b)
{
	swap(list_b);
	ft_printf("sb\n");
}
