/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 07:21:54 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(const char *arg)
{
	size_t	i;
	int		cast;

	i = 0;
	while (arg[i])
	{
		cast = (int)arg[i];
		if (!ft_isdigit(cast))
			return (0);
		i++;
	}
	return (1);
}

t_stack	init_stack(int argc, char *argv[])
{
	t_stack		stack;
	t_element	elem;
	size_t		i;

	i = 0;
	stack.id = 65;
	stack.elements = ft_calloc((argc - 1), sizeof(t_element));
	while (argv[i])
	{
		if (valid_input(argv[i]))
		{
			elem.stack = stack;
			elem.value = ft_atoi(argv[i]);
			stack.elements[i] = elem;
		}
		i++;
	}
	return (stack);
}


int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 1)
	{
		ft_putstr_fd("Couldn't run program without input\n", 1);
		return (0);
	}

	stack = init_stack(argc, argv);
	push_swap(stack);
	free_stack(&stack);
	return (1);
}

// 47 2 89 16 53 71 8 94 30 61