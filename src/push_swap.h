/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/19 06:30:40 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// =========== Type definition ===========

typedef struct s_history
{
	unsigned long	amount;
	char			**moves;
}	t_history;

// ============= Functions =============

void	push_swap(t_list *list_a);
void	push(t_list **dest, t_list **src);
void	swap(t_list **list);
void	rotate(t_list **list);
void	rev_rotate(t_list **stack);

void	display_list(t_list *list);
int		sort_complete(t_list **list);

#endif