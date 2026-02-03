/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:59:15 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/03 21:32:08 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_route
{
	struct s_list	*node;
	struct s_list	*target;
	int				a_direction;
	size_t			a_size;
	int				a_steps;
	int				b_direction;
	size_t			b_size;
	int				b_steps;
}	t_route;

// =========== Sort algorithm ============

void		sort_stack(t_list **a, t_list **b);
void		mini_sort(t_list **a, t_list **b);
void		execute_route(t_list **a, t_list **b, t_route route);
int			ascending(t_list *list);
int			optimal_place(t_list *a, t_list *b);
void		run(t_list **a, t_list **b);
void		finalize(t_list **a);
t_route		*init_route(t_list *node, t_list *target, size_t a_s, size_t b_s);
t_route		*fill_route(t_route *route, int steps, int self_steps);
t_route		*get_shortest(t_route *route_1, t_route *route_2);
void		free_routes(t_route **routes);

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

void		set_rankings(t_list *list);
void		display_list(t_list *list);
int			exceed_largest(t_list *list, t_list *item);
int			exceed_smallest(t_list *list, t_list *item);
void		free_list(t_list *list);

#endif