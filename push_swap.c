/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 04:48:32 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/13 05:54:22 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_element	*tmp;

	if (stack->elements[1] != NULL)
	{
		tmp = stack->elements[1];
		stack->elements[1] = stack->elements[0];
		stack->elements[0] = tmp;
	}
	write(1, "s", 1);
}

void	push(t_stack *dest, t_stack *src)
{
	size_t	src_size;
	size_t	alloc_dst;
	size_t	sin;
	int		din;

	src_size = calc_stack_size(src);
	alloc_dst = (calc_stack_size(dest) + 1);
	sin = 0;
	if (src_size >= 1)
	{
		dest->elements = ft_calloc(alloc_dst, sizeof(t_element *));
		if (dest->elements[din]->value == NULL)
			dest->elements[din] = src->elements[sin];
		while (sin < src_size)
		{
			if (src->elements[sin + 1])
				src->elements[sin] = src->elements[sin + 1];
			sin++;
			if (sin == (src_size - 1))
				src->elements[sin] = NULL;
		}
	}
	ft_printf("p%c\n", dest->id + 32);
}

void	rotate(t_stack *stack)
{
	int			i;
	size_t		size;
	t_element	*elem;

	i = 0;
	size = calc_stack_size(stack);
	elem = ft_calloc(1, sizeof(t_element));
	elem = stack->elements[i];
	while (i < calc_stack_size(stack))
	{
		if (stack->elements[i + 1])
			stack->elements[i] = stack->elements[i + 1];
		i++;
		if (i == (calc_stack_size(stack) - 1))
			stack->elements[i] = elem;
	}
	write(1, "r", 1);
}


void	reverse_rotate(t_stack *stack)
{
	size_t		i;
	t_element	*elem;

	i = (calc_stack_size(stack) - 1);
	elem = ft_calloc(1, sizeof(t_element));
	elem = stack->elements[i];
	while (i > 0)
	{
		stack->elements[i] = stack->elements[i - 1];
		i--;
	}
	stack->elements[i] = elem;
	write(1, "rr", 2);
}


void	push_swap(t_stack *stack)
{
	t_stack	*stackb;

	stackb = ft_calloc(1, sizeof(t_stack));
	stackb->id = 66;
	stackb->elements = ft_calloc(calc_stack_size(stack), sizeof(t_element));
	ft_printf("\nBeginning of push_swap\n\n");
	display_stack(stack);
	ft_printf("\n");
}

// having directions of: sa sb ss pa pb ra rb rr rra rrb rrr 