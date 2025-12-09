/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:48:32 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/09 17:07:14 by brogaar          ###   ########.fr       */
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

void	push(t_stack *dest, t_stack *src)
{
	static int	destpos;

	if ((*src).elements[1].value != 0)
	{
		if ((*dest).elements[1].value == 0)
		{
			destpos = 1;
			(*dest).elements[1].value = (*src).elements[1].value;
		}
	}
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
	stack_b.elements = ft_calloc(calc_stack_size(stack), sizeof(t_element));
	i = 1;
	ft_printf("Stack A;\t\tStack B;\n");
	while (stack.elements[i].value != 0)
	{
		ft_printf("next: %d\t\t\t", stack.elements[i].next->value);
		if (stack_b.elements[i].value > 0)
			ft_printf("%d", stack_b.elements[i].value);
		else
			ft_printf("(zero)");
		ft_printf("\n");
		i++;
	}
}

// having directions of: sa sb ss pa pb ra rb rr rra rrb rrr 