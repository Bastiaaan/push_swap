/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/13 02:57:14 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calc_stack_size(t_stack *stack)
{
	unsigned int	size;

	size = 0;
	while (stack->elements[size])
		size++;
	return (size);
}

void	reindex(t_stack *stack, void *content)
{
	ft_printf("not implemented yet\n");
}

void	display_stack(t_stack *stack)
{
	size_t	pos;

	pos = 0;
	ft_printf("========== Displaying Stack #%c ==========\n", stack->id);
	while (pos < calc_stack_size(stack))
	{
		ft_printf("%d", stack->elements[pos]->value);
		ft_printf("\n");
		pos++;
	}
	ft_printf("==========================================\n");
}

void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->elements[i])
	{
		free(stack->elements[i]);
		i++;
	}
}
