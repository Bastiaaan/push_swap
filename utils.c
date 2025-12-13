/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/13 07:31:42 by brogaar          ###   ########.fr       */
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

void	reindex(t_stack *stack, void *element)
{
	size_t		i;
	t_element	*elem;

	i = 0;
	if (element == NULL)
	{
		while (i < calc_stack_size(stack))
		{
			stack->elements[i] = stack->elements[i + 1];
			i++;
		}
		stack->elements[i] = NULL;
	}
	else
	{
		i = calc_stack_size(stack);
		while (i > 0 && i--)
		{
			stack->elements[i] = stack->elements[i - 1];
		}
		elem = ft_calloc(1, sizeof(t_element));
		elem = element;
		stack->elements[i] = elem;
	}
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
