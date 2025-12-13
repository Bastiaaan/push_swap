/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/13 07:25:19 by brogaar          ###   ########.fr       */
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

char	**split_args(char *arg)
{
	char	**argv;

	argv = ft_split(arg, ' ');
	if (!argv)
		return (NULL);
	return (argv);
}

size_t	argslen(char **splt)
{
	size_t	s;

	s = 0;
	while (splt[s])
		s++;
	return (s);
}

t_stack	*init_stack(int argc, char *argv[])
{
	t_stack		*stack;
	int			i;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	stack->id = 65;
	stack->elements = ft_calloc((argc), sizeof(t_element));
	if (!stack->elements)
		return (NULL);
	while (argv[i])
	{
		if (valid_input(argv[i]))
		{
			stack->elements[i - 1] = ft_calloc(1, sizeof(t_element));
			stack->elements[i - 1]->value = ft_atoi(argv[i]);
			stack->elements[i - 1]->stack = stack;
		}
		i++;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**corrected;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	else if (argc == 2 && ft_strchr(argv[1], 32) != NULL)
	{
		corrected = split_args(argv[1]);
		stack = init_stack(argslen(corrected), corrected);
		free(corrected);
	}
	else
		stack = init_stack((argc), argv);
	push_swap(stack);
	return (1);
}

// make re && ./push_swap.a 47 5 89 16 53 71 8 94 30 61 -- normal test
// make debug && gdb ./push_swap.test 47 5 89 16 53 71 8 94 30 61 -- debug test with gdb