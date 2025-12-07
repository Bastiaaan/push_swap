/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 09:53:57 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

// ========== Type definition ========== 

typedef struct s_element	t_element;

typedef struct s_stack
{
	char		id;
	t_element	*elements;
}	t_stack;

typedef struct s_element
{
	int		value;
	t_stack	stack;	
}	t_element;

// ============= Functions =============

void	push_swap(t_stack stack);
size_t	calc_stack_size(t_stack stack);
int		isdone(t_stack stack);
void	free_stack(t_stack *stack);
void	reindex_stack(t_stack *stack, int src);


#endif