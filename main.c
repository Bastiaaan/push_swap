/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/09 21:35:25 by brogaar          ###   ########.fr       */
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
	int			i;

	i = 1;
	stack.id = 65;
	stack.elements = ft_calloc((argc - 1), sizeof(t_element));
	while (argv[i])
	{
		if (valid_input(argv[i]))
		{
			elem.stack = &stack;
			if (argv[i + 1] != NULL)
			{
				elem.next = ft_calloc(1, sizeof(t_element));
				elem.next->value = ft_atoi(argv[i + 1]);
			}
			elem.value = ft_atoi(argv[i]);
			stack.elements[i - 1] = elem;
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

// make re && ./push_swap.a 47 5 89 16 53 71 8 94 30 61 -- normal test
// make debug && gdb ./push_swap.a 47 5 89 16 53 71 8 94 30 61 -- debug test with gdb