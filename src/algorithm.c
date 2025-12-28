/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/27 18:05:15 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*define_action(t_list *a, t_list *b)
{
	char	*move;
	
	if (ft_lstsize(a) > 1)
	{
		if (a->content < a->next->content && a->content < ft_lstlast(a)->content)
			move = ft_strdup("pb");
		if (a->content > a->next->content && a->next->content < ft_lstlast(a)->content)
			move = ft_strdup("sa");
		if (a->content > ft_lstlast(a)->content && a->next->content > ft_lstlast(a)->content)
			move = ft_strdup("rra");
		if (a->content > a->next->content && a->content > ft_lstlast(a)->content)
			move = ft_strdup("ra");
	}
	if (!move)
		move = define_action_undetermined(a, b);
	return (move);
}

char	*define_action_undetermined(t_list *a, t_list *b)
{
	char	*move;

	if (ft_lstsize(b) > 0)
	{
		if (b->content > b->next->content && b->content > ft_lstlast(b) && b->content < a->content)
			move = ft_strdup("pa");
		else if (b->content > a->content)
			move = ft_strdup("ra");
		if (b->content < ft_lstlast(b)->content && b->next->content > ft_lstlast(b)->content)
			move = ft_strdup("rb");
		if (b->content < ft_lstlast(b)->content && ft_lstlast(b)->content > b->next->content)
			move = ft_strdup("rrb");
		if (b->content < b->next->content && ft_lstlast(b)->content < b->next->content)
			move = ft_strdup("sb");
	}
	return (move);
}

void	exec_action(char *action, t_list **a, t_list **b)
{
	if (action != '\0')
	{
		if (ft_strncmp(action, "pa", ft_strlen(action)) == 0)
			pa(a, b);
		if (ft_strncmp(action, "pb", ft_strlen(action)) == 0)
			pb(b, a);
		if (ft_strncmp(action, "ra", ft_strlen(action)) == 0)
			ra(a);
		if (ft_strncmp(action, "rb", ft_strlen(action)) == 0)
			rb(b);
		if (ft_strncmp(action, "rr", ft_strlen(action)) == 0)
			rr(a, b);
		if (ft_strncmp(action, "rra", ft_strlen(action)) == 0)
			rra(a);
		if (ft_strncmp(action, "rrb", ft_strlen(action)) == 0)
			rrb(b);
		if (ft_strncmp(action, "rrr", ft_strlen(action)) == 0)
			rrr(a, b);
		if (ft_strncmp(action, "sa", ft_strlen(action)) == 0)
			sa(a);
		if (ft_strncmp(action, "sb", ft_strlen(action)) == 0)
			sb(b);
		if (ft_strncmp(action, "ss", ft_strlen(action)) == 0)
			ss(a, b);
	}
}

void	run(t_list *a, t_list *b)
{
	unsigned int	moves;
	unsigned int	limit;
	unsigned int	lstsize;
	char			*action;

	limit = 25;
	moves = 0;
	lstsize = ft_lstsize(a);
	while (limit > 0 && !sort_complete(a, lstsize))
	{
		action = define_action(a, b);
		exec_action(action, &a, &b);
		moves++;
		limit--;
		free(action);
	}
	if (sort_complete(a, lstsize))
		ft_printf("\n===== Sorting complete =====\n\n===== Moves detected: %u\n\n", moves);
	else
	{
		ft_printf("\nStack #A\n\n");
		display_list(a);
		ft_printf("Stack #B\n\n");
		display_list(b);
	}
}

	/*
	=================== Rotate ===================
	
	execute ra when first is larger than second and second is smaller than last
	execute rb when first is smaller than second and second is larger than last
	
	=============== Reverse Rotate ===============
	
	execute rra when first is larger than last and smaller than second
	execute rrb when first is smaller than last and larger than second.
	
	==================== Swap ====================
	
	execute sa when second is smaller than first and both are smaller than last
	execute sb when second is larger than first and both are larger than last

	==================== Push ====================

	execute pb when first is either smaller than second and smaller than last
	execute pa when first is either larger than second and larger than last 
	ONLY when list a is sorted in an ascending order	
	*/