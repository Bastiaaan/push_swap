/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/30 08:51:08 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*cheapest(t_list *a, t_list *b)
{
	t_list	*cheapest;
	int		steps_first;
	int		steps_second;
	int		steps_last;

	steps_first = calc_steps_pa(a, b);
	steps_second = calc_steps_pa(a, b->next);
	steps_last = calc_steps_pa(a, ft_lstlast(b));
	if (steps_first <= steps_second && steps_first <= steps_last)
		cheapest = b;
	else if (steps_second <= steps_first && steps_second <= steps_last)
		cheapest = b->next;
	else if (steps_last <= steps_first && steps_last <= steps_first)
		cheapest = ft_lstlast(b);
	else
		cheapest = NULL;
	return (cheapest);
}

static void	prep_pa(t_list **a, t_list **b, t_list *c, int direction)
{
	int	steps;

	steps = calc_steps_pa(*a, c);
	while (steps > 0)
	{
		if (direction > 0)
		{
			if (steps == 1
				&& (*b)->next->content == c->content
				&& (*b)->next->content < (*a)->next->content)
				rr(a, b);
			else
				ra(a);
		}
		else
		{
			if (steps == 1
				&& ft_lstlast(*a)->content > ft_lstlast(*b)->content
				&& ft_lstlast(*b)->content == c->content)
				rrr(a, b);
			else
				rra(a);
		}
		steps--;
	}
}

static void	choose_cheapest(t_list *a, t_list *b, size_t size)
{
	int		direction;
	int		steps;
	t_list	*chosen;

	chosen = cheapest(a, b);
	steps = calc_steps_pa(a, chosen);
	direction = calc_direction_pa(a, chosen);
	if (ft_lstsize(a) >= 40 && steps > (ft_lstsize(a) / 4))
		re_roll(&a, &b, chosen);
	else
	{
		prep_pa(&a, &b, chosen, direction);
		correct_stack(&a, &b, chosen);
		if ((b->content < a->content
				&& b->content > ft_lstlast(a)->content)
			|| (ascending(a) && exceed_largest(a, chosen)
				|| exceed_smallest(a, chosen)))
			pa(&a, &b);
	}
	if (!sort_complete(a, size))
		sort_stack(a, b, size);
}

void	sort_stack(t_list *a, t_list *b, size_t size)
{
	int	direction;

	if (ft_lstsize(b) == 1)
	{
		direction = calc_direction_pa(a, b);
		while (b->content > a->content
			|| b->content < ft_lstlast(a)->content)
		{
			if (direction > 0)
				ra(&a);
			else
				rra(&a);
		}
		pa(&a, &b);
		direction = calc_direction_exceed(a);
		while (!sort_complete(a, size))
		{
			if (direction > 0)
				ra(&a);
			else
				rra(&a);
		}
	}
	else if (!sort_complete(a, size))
		choose_cheapest(a, b, size);
}
