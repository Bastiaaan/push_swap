/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 12:40:28 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_instructions
{
	struct t_list	*target;
	struct t_list	*src;
	int				rot_a;
	int				rot_b;
	int				rev_a;
	int				rev_b;
	int				rr;
	int				rrr;
}	t_instructions;


// =========== Sort algorithm ============

void		sort_stack(t_list *a, t_list *b, size_t size);
void		mini_sort(t_list **a, t_list **b);
int			calc_steps_pa(t_list *dest, t_list *elem);
int			calc_exceed_pa(t_list *a);
void		re_roll(t_list **a, t_list **b, t_list *chosen);
void		correct_stack(t_list **a, t_list **b, t_list *cheapest);
int			ascending(t_list *list);
int			descending(t_list *list);
void		run(t_list *a, t_list *b);

// ========= Push-swap Functions =========

void		push(t_list **dest, t_list **src);
void		swap(t_list **list);
void		rotate(t_list **list);
void		rev_rotate(t_list **stack);

// ========= Push-swap executed ==========

void		pa(t_list **list_a, t_list **list_b);
void		ra(t_list **list_a);
void		rra(t_list **list_a);
void		sa(t_list **list_a);

void		pb(t_list **list_b, t_list **list_a);
void		rb(t_list **list_b);
void		rrb(t_list **list_b);
void		sb(t_list **list_b);

void		rr(t_list **list_a, t_list **list_b);
void		rrr(t_list **list_a, t_list **list_b);
void		ss(t_list **list_a, t_list **list_b);

// ======== additional functions =========

t_list		*clone(t_list *src);
void		set_rankings(t_list *list);
void		display_list(t_list *list);
int			exceed_largest(t_list *list, t_list *item);
int			exceed_smallest(t_list *list, t_list *item);
int			sort_complete(t_list *list, size_t original_size);
int			calc_direction_pa(t_list *list, t_list *item);
int			calc_direction_exceed(t_list *list);
int			calc_direction_pa(t_list *a, t_list *src);
void		free_list(t_list *list);

#endif