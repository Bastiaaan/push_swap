/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:00:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/28 14:00:17 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	ft_printf("pa\n");
}

void	ra(t_list **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
}

void	rra(t_list **list_a)
{
	rev_rotate(list_a);
	ft_printf("rra\n");
}

void	sa(t_list **list_a)
{
	swap(list_a);
	ft_printf("sa\n");
}
