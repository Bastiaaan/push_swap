/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:24:55 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/28 19:13:15 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish(t_list **a, t_list **b, int borrowed)
{
	while (borrowed > 0)
	{
		if (borrowed >= 2 && (*b)->content < (*b)->next->content)
			sb(b);
		else if ((*b)->content > (*a)->content
			&& (*a)->content < (*a)->next->content)
			ra(a);
		else if ((*b)->content < (*a)->content
			&& (*b)->content < ft_lstlast(*a)->content
			&& ft_lstlast(*a)->content < (*a)->content)
			rra(a);
		else if ((*b)->content < (*a)->content
			&& ((*a)->content < ft_lstlast(*a)->content
				|| (*b)->content > ft_lstlast(*a)->content
				|| ascending(*a) || exceed_smallest(*a, *b)))
		{
			pa(a, b);
			borrowed--;
		}
	}
}

// only following b options are allowed: pb and sb.
void	mini_sort(t_list **a, t_list **b)
{
	int	borrowed;

	borrowed = 0;
	while (!ascending(*a))
	{
		if (ft_lstsize(*a) >= 2
			&& (*a)->content > (*a)->next->content && !exceed_largest(*a, *a))
			sa(a);
		else if ((*a)->content < (*a)->next->content
			&& (*a)->content < ft_lstlast(*a)->content)
		{
			pb(b, a);
			borrowed++;
		}
		else if (ft_lstlast(*a)->content > (*a)->content)
			rra(a);
		else
			ra(a);
	}
	finish(a, b, borrowed);
}
