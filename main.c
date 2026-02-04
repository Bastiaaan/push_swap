/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2026/02/04 15:59:51 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

void	set_rankings(t_list *list)
{
	t_list	*lst1;
	t_list	*lst2;
	int		rank;

	lst1 = list;
	while (lst1)
	{
		lst2 = list;
		rank = 0;
		while (lst2)
		{
			if (lst1->content > lst2->content)
				rank++;
			lst2 = lst2->next;
		}
		lst1->rank = rank;
		lst1 = lst1->next;
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
		if (!ft_isdigit(cast) || cast >= 2147483647)
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
	new = NULL;
	if (!args)
		return (NULL);
	while (args[i])
	{
		if (valid_input(args[i]))
		{
			tmp = ft_lstnew(ft_atoi(args[i]));
			if (new == 0x0)
				new = tmp;
			else
				ft_lstadd_back(&new, tmp);
		}
		i++;
	}
	free(args);
	return (new);
}

t_list	*handleargv(char *argv[])
{
	t_list	*list;
	t_list	*new;
	int		arg_cast;
	int		i;

	list = NULL;
	i = 1;
	while (argv[i])
	{
		if (valid_input(argv[i]))
		{
			arg_cast = ft_atoi(argv[i]);
			new = ft_lstnew(arg_cast);
			if (list == NULL)
				list = new;
			else
				ft_lstadd_back(&list, new);
		}
		else
			return (NULL);
		i++;
	}
	return (list);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc == 2 && ft_strchr(argv[1], 32) != NULL)
		list_a = handlebigargv(argv[1]);
	else
		list_a = handleargv(argv);
	if (!ft_lstunique(&list_a) || list_a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	set_rankings(list_a);
	run(&list_a, &list_b);
	free_list(list_a);
	return (0);
}
