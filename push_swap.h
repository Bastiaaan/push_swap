/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/13 07:20:53 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

// ========== Type definition ========== 

typedef struct s_element	t_element;

typedef struct s_stack
{
	char		id;
	t_element	**elements;
}	t_stack;

typedef struct s_element
{
	int			value;
	t_stack		*stack;
}	t_element;

// ============= Functions =============

void			push_swap(t_stack *stack);
void			push(t_stack *dest, t_stack *src);
void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);

unsigned int	calc_stack_size(t_stack *stack);
void			reindex(t_stack *stack, void *content);
void			free_stack(t_stack *stack);
void			display_stack(t_stack *stack);
void			reindex(t_stack *stack, void *content);

#endif