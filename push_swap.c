/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:48:32 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 09:58:56 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_element	tmp;

	tmp = (*stack).elements[1];
	(*stack).elements[1] = (*stack).elements[2];
	(*stack).elements[2] = tmp;
}

t_stack	push(t_stack *dest, t_stack *src)
{
	size_t	start;
	t_stack	new;

	start = 1;
	new.id = (*src).id;
	new.elements = ft_calloc((calc_stack_size(*src) - 1), sizeof(t_element));
	dest->elements = ft_calloc((calc_stack_size(*dest) + 1), sizeof(t_element));
	if ((*src).elements[1].value != 0)
	{
		(*dest).elements[1].stack.id = (*src).id;
		if ((*dest).elements[1].value == 0)
			(*dest).elements[1].value = (*src).elements[1].value;
		else
			reindex_stack(dest, (*src).elements[1].value);
		while ((*src).elements[start + 1].value != 0)
		{
			new.elements[start] = (*src).elements[start + 1];
			start++;
		}
		free_stack(src);
	}
	return (new);
}

void	rotate(t_stack *stack)
{
	size_t	size;
	size_t	i;

	size = calc_stack_size(*stack);
	i = 1;
	ft_printf("Not implemented yet");
}


void	reverse_rotate(t_stack *stack)
{
	size_t	size;
	size_t	i;

	size = calc_stack_size(*stack);
	i = 1;
	ft_printf("Not implemented yet");
}


void	push_swap(t_stack stack)
{
	size_t	i;
	t_stack	stack_b;

	stack_b.id = 66;
	i = 1;
	stack = push(&stack_b, &stack);
	stack = push(&stack_b, &stack);
	stack = push(&stack_b, &stack);
	ft_printf("Stack A;\t\tStack B;\n");
	while (stack.elements[i].value != 0)
	{
		ft_printf("%d\t\t\t", stack.elements[i].value);
		if (stack_b.elements[i].value > 0)
			ft_printf("%d", stack_b.elements[i].value);
		else
			ft_printf("(zero)");
		ft_printf("\n");
		i++;
	}
}

// having directions of: sa sb ss pa pb ra rb rr rra rrb rrr 