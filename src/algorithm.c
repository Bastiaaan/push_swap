/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/04 09:07:43 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_route	*get_shortest(t_route *route_1, t_route *route_2)
{
	if (!route_1 || route_1->node == NULL)
		return (route_2);
	if (!route_2 || route_2->node == NULL)
		return (route_1);
	if ((route_1->a_steps + route_1->b_steps)
		< (route_2->a_steps + route_2->b_steps))
		return (route_1);
	return (route_2);
}

static t_route	*select_best(t_route **route)
{
	t_route		*best;
	t_route		*current;
	int			index;

	index = 0;
	while (route[index])
	{
		if (index == 0)
			best = route[index];
		else
		{
			current = route[index];
			best = get_shortest(best, current);
		}
		index++;
	}
	return (best);
}

static t_route	**get_routes(t_list **a, t_list **b, size_t a_s, size_t b_s)
{
	t_list			*la;
	t_list			*lb;
	t_route			**routes;
	unsigned int	moves_a;
	unsigned int	moves_b;

	routes = ft_calloc(ft_lstsize(*b) + 1, sizeof(t_route *));
	if (!routes)
		return (NULL);
	lb = *b;
	moves_b = 0;
	while (lb)
	{
		la = *a;
		moves_a = 0;
		calc_stack_a(&la, lb, &moves_a);
		routes[moves_b] = init_route(lb, la, a_s, b_s);
		routes[moves_b] = fill_route(routes[moves_b], moves_a, moves_b);
		moves_b++;
		lb = lb->next;
	}
	return (routes);
}

int	pa_compatible(t_list *a, t_list *b)
{
	if (!b || !a)
		return (0);
	if ((b->content < a->content && optimal_place(a, b))
		|| (exceed_largest(a, b) && ascending(a)))
		return (1);
	return (0);
}

void	sort_stack(t_list **a, t_list **b)
{
	t_route	*chosen;
	t_route	**routes;
	int		i;

	i = 0;
	while (ft_lstsize((*b)) > 0)
	{
		routes = get_routes(a, b, ft_lstsize(*a), ft_lstsize(*b));
		chosen = select_best(routes);
		execute_route(a, b, *chosen);
		pa(a, b);
		free_routes(routes);
	}
	finalize(a);
}
