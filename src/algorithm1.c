/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:58:13 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/03 00:47:08 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_double(t_list **a, t_list **b, t_route *route)
{
	while (route->a_steps > 0 && route->b_steps > 0)
	{
		if (route->a_direction > 0)
			rr(a, b);
		else
			rrr(a, b);
		route->a_steps--;
		route->b_steps--;
	}
}

void	execute_route(t_list **a, t_list **b, t_route route)
{
	if (route.a_direction == route.b_direction
		&& route.a_steps > 0 && route.b_steps > 0)
		execute_double(a, b, &route);
	while (route.a_steps > 0)
	{
		if (route.a_direction > 0)
			ra(a);
		else
			rra(a);
		route.a_steps--;
	}
	while (route.b_steps > 0)
	{
		if (route.b_direction > 0)
			rb(b);
		else
			rrb(b);
		route.b_steps--;
	}
}

t_route	*init_route(t_list *node, t_list *target, size_t a_size, size_t b_size)
{
	t_route	*route;

	route = ft_calloc(1, sizeof(t_route));
	if (!route)
		return (NULL);
	route->node = node;
	route->target = target;
	route->a_size = a_size;
	route->b_size = b_size;
	return (route);
}

t_route	*fill_route(t_route *route, int steps, int self_steps)
{
	route->a_direction = 0;
	route->b_direction = 0;
	if (steps > (route->a_size / 2))
	{
		route->a_steps = route->a_size - steps;
		route->a_direction = -1;
	}
	else
	{
		route->a_direction = 1;
		route->a_steps = steps;
	}
	if (self_steps > (route->b_size / 2))
	{
		route->b_steps = route->b_size - self_steps;
		route->b_direction = -1;
	}
	else
	{
		route->b_direction = 1;
		route->b_steps = self_steps;
	}
	return (route);
}
