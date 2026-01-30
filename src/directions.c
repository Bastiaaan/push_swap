/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:36:03 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 04:00:10 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_pa(t_list *a, t_list *node)
{
	t_list	*cpy;
	int		steps;

	steps = 0;
	cpy = clone(a);
	while (!(cpy->rank > node->rank
			&& ft_lstlast(cpy)->rank < cpy->rank)
		&& steps < ft_lstsize(a))
	{
		if (node->rank < cpy->rank
			&& ft_lstlast(cpy)->rank < cpy->rank)
			rev_rotate(&cpy);
		else if (node->rank > cpy->rank
			&& ft_lstlast(cpy)->rank < cpy->rank)
			rotate(&cpy);
		steps++;
	}
	return (steps);
}
