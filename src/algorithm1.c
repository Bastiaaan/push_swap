/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:58:13 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/26 17:36:13 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_stack(t_list **a, t_list **b, t_list *cheapest)
{
	if (ft_lstlast(*a)->content == cheapest->content)
		rra(a);
	if ((*a)->next->content == cheapest->content)
	{		
		if ((*a)->content > ft_lstlast(*a)->content)
			ra(a);
		else
			sa(a);	
	}
}