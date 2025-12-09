/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:32:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/09 16:47:35 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calc_stack_size(t_stack stack)
{
	size_t	size;

	size = 0;
	while (stack.elements[size + 1].value != 0)
	{
		size++;
	}
	return (size);
}

int	isdone(t_stack stack)
{
	size_t		i;
	t_element	next;

	i = 1;
	while (sizeof(stack.elements[i].value) > 0)
	{
		next = stack.elements[i + 1];
		if (next.value != 0 && stack.elements[i].value >= next.value)
			return (0);
		i++;
	}
	return (1);
}

char	*determine_action(void)
{
	char	*action;

	action = ft_strdup("sa");
	return ("Not implemented yet");
}

void	free_stack(t_stack *stack)
{
	if (stack->elements != NULL)
		free(stack->elements);
}
