/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:57:36 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/30 15:05:04 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function defines the fundamental moves of stack A. 
char	*define_action(t_list *a, t_list *b)
{
	char	*move;

	move = '\0';
	if (ft_lstsize(a) >= 2 && ft_lstsize(b) >= 2)
	{
		if (ft_lstlast(a)->content < a->content
			&& ft_lstlast(a)->content < a->next->content
			&& ft_lstlast(b)->content > b->content
			&& ft_lstlast(b)->content > b->next->content)
			move = ft_strdup("rrr");
		if (a->content > ft_lstlast(a)->content
			&& a->next->content < ft_lstlast(a)->content
			&& b->content < ft_lstlast(b)->content
			&& b->next->content > ft_lstlast(b)->content)
			move = ft_strdup("rr");
		if (a->next->content < a->content
			&& a->content < ft_lstlast(a)->content
			&& b->next->content > b->content
			&& b->content > ft_lstlast(b)->content)
			move = ft_strdup("ss");
	}
	if (!move)
		move = define_action_undetermined1(a, b);
	return (move);
}

// here whenever stack A is ready to push to stack B, 
char	*define_action_undetermined1(t_list *a, t_list *b)
{
	char	*move;

	move = '\0';
	if (ft_lstsize(a) >= 2 && !ascending(a))
	{
		if (a->content > ft_lstlast(a)->content
			&& a->next->content < ft_lstlast(a)->content)
			move = ft_strdup("ra");
		if (ft_lstlast(a)->content < a->content
			&& ft_lstlast(a)->content < a->next->content)
			move = ft_strdup("rra");
		if (a->next->content < a->content
			&& a->content < ft_lstlast(a)->content)
			move = ft_strdup("sa");
	}
	if (ascending(a) && b->content < a->content
		&& ft_lstsize(b) >= 1 && descending(b))
		move = ft_strdup("pa");
	if (!move)
		move = define_action_undetermined2(a, b);
	return (move);
}

char	*define_action_undetermined2(t_list *a, t_list *b)
{
	char	*move;

	move = '\0';
	if (ft_lstsize(a) >= 1 && a->content < a->next->content
		&& a->content < ft_lstlast(a)->content)
	{
		if (a->content < b->content)
			move = ft_strdup("rrb");
		else if (ft_lstsize(b) < 3 || a->content > b->content && descending(b))
			move = ft_strdup("pb");
		if (!descending(b) && a->content > b->content
			&& a->content < ft_lstlast(b)->content)
			ft_printf("");
	}
	if (!move)
		move = define_action_undetermined3(a, b);
	return (move);
}

char	*define_action_undetermined3(t_list *a, t_list *b)
{
	char	*move;

	move = '\0';
	if (ft_lstsize(b) >= 2 && !descending(b))
	{
		if (b->content < ft_lstlast(b)->content
			&& b->next->content < ft_lstlast(b)->content)
			move = ft_strdup("rb");
		if (ft_lstlast(b)->content > b->content
			&& ft_lstlast(b)->content > b->next->content)
			move = ft_strdup("rrb");
		if (b->next->content > b->content
			&& b->content > ft_lstlast(b)->content)
			move = ft_strdup("sb");
	}
	if (!move)
		move = define_action(a, b);
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