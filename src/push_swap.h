/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/28 16:01:25 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

// =========== Sort algorithm ============

char			*define_action(t_list *a, t_list *b);
char			*define_action_undetermined(t_list *a, t_list *b);
int				ascending(t_list *list);
int				descending(t_list *list);
void			exec_action(char *action, t_list **a, t_list **b);
void			run(t_list *a, t_list *b);

// ========= Push-swap Functions =========

void			push(t_list **dest, t_list **src);
void			swap(t_list **list);
void			rotate(t_list **list);
void			rev_rotate(t_list **stack);

// ========= Push-swap executed ==========

void			pa(t_list **list_a, t_list **list_b);
void			ra(t_list **list_a);
void			rra(t_list **list_a);
void			sa(t_list **list_a);

void			pb(t_list **list_b, t_list **list_a);
void			rb(t_list **list_b);
void			rrb(t_list **list_b);
void			sb(t_list **list_b);

void			rr(t_list **list_a, t_list **list_b);
void			rrr(t_list **list_a, t_list **list_b);
void			ss(t_list **list_a, t_list **list_b);

// ======== additional functions =========

void			assign_list(char id, t_list *list);
void			display_list(t_list *list);
int				exceed_largest(t_list *list, t_list *item);
int				exceed_smallest(t_list *list, t_list *item);
int				sort_complete(t_list *list, unsigned int original_size);
unsigned int	times_greater(t_list *list);
unsigned int	times_smaller(t_list *list);
void			free_list(t_list **list);

#endif