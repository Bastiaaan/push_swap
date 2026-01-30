/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:58:13 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 07:35:24 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_stack(t_list **a, t_list **b, t_list *cheapest)
{
	if (cheapest == (*b)
		&& (*b)->content < (*b)->next->content
		&& calc_steps_pa(*a, *b) == 0
		&& calc_steps_pa(*a, (*b)->next) == 0)
		sb(b);
	else if (ft_lstlast(*b) == cheapest)
		rrb(b);
	else if ((*b)->next == cheapest)
		rb(b);
}

void	re_roll(t_list **a, t_list **b, t_list *chosen)
{
	int	direction;

	direction = calc_direction_pa(&a, chosen);
	while (calc_steps_pa(*a, *b) > (ft_lstsize(&a) / 4)
		&& calc_steps_pa(*a, (*b)->next) > (ft_lstsize(&a) / 4)
		&& calc_steps_pa(*a, ft_lstlast(*b)) > (ft_lstsize(&a) / 4))
	{
		if (direction > 0)
			rr(a, b);
		else
			rrr(a, b);
	}
}
