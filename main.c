/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/06 15:37:10 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

void	assign_list(char id, t_list *list)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		lst->id = id;
		lst = lst->next;
	}
}

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

t_list	*handlebigargv(char *argv)
{
	t_list	*new;
	t_list	*tmp;
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv, ' ');
	if (!args)
		return (NULL);
	new = ft_calloc(1, sizeof(t_list));
	while (args[i])
	{
		if (valid_input(args[i]))
		{
			tmp = ft_lstnew((long)ft_atoi(args[i]));
			ft_lstadd_back(&new, tmp);
		}
		i++;
	}
	free(args);
	assign_list(65, new);
	return (new);
}

t_list	*handleargv(char *argv[])
{
	t_list	*list;
	t_list	*tmp;
	int		arg_cast;
	int		i;

	i = 1;
	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (NULL);
	while (argv[i])
	{
		if (valid_input(argv[i]))
		{
			arg_cast = ft_atoi(argv[i]);
			tmp = ft_lstnew((long)arg_cast);
			ft_lstadd_back(&list, tmp);
		}
		i++;
	}
	list = list->next;
	assign_list(65, list);
	return (list);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc == 2 && ft_strchr(argv[1], 32) != NULL)
		list_a = handlebigargv(argv[1]);
	else
		list_a = handleargv(argv);
	list_b = ft_calloc(ft_lstsize(list_a), sizeof(t_list));
	if (!list_b)
		return (0);
	run(list_a, list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (1);
}
// testing already sorted list: 4 5 234 310 400 673 824
// make re && ./push_swap.a 30992 25177 1657 1058 1988 2295 36301 43687 3839 918 28412 -- normal test
// make debug && gdb ./push_swap.test -- debug test with gdb47 5 89 16 53 71 8 94 30 61