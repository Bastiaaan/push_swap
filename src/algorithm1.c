/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:58:13 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 17:49:53 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_max(t_list *stack, t_list *src)
{

}

t_route	set_route(t_list *node, t_list *target, int steps, int self_steps)
{
	t_route	route;

	route.node = node;
	route.target = target;
	route.steps = steps;
	route.self_steps = self_steps;
	route.size = ft_lstsize(route.node);
	if (route.steps > (route.size / 2))
		route.direction = -1;
	else
		route.direction = 1;
	if (route.self_steps > (route.size / 2))
		route.self_direction = -1;
	else
		route.self_direction = 1;
	return (route);
}
