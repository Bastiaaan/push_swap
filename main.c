/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/17 09:47:16 by brogaar          ###   ########.fr       */
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
	new = NULL;
	if (!args)
		return (NULL);
	while (args[i])
	{
		if (valid_input(args[i]))
		{
			tmp = ft_lstnew((long)ft_atoi(args[i]));
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
			new = ft_lstnew((long)arg_cast);
			if (list == NULL)
				list = new;
			else
				ft_lstadd_back(&list, new);
		}
		i++;
	}
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
	list_b = NULL;
	set_rankings(list_a);
	run(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
	return (1);
}
// testing already sorted list: 4 5 234 310 400 673 824
// make re && ./push_swap.a 34842 23299 6782 24558 9692 24363 33194 26337 11711 23180 27713 13812 48777 627 35975 16967 35071 8356 29223 1722 27488 3439 27344 33413 27411 6976 40513 43503 45055 19483 27822 17801 40851 46613 882 48590 6628 23917 22417 7183 41198 31740 1301 1992 18882 949 46214 21256 43855 7963 -- normal test
// make debug && gdb ./push_swap.test -- debug test with gdb47 5 89 16 53 71 8 94 30 61
// ./push_swap.a 44865 39502 15069 29203 15669 44209 46919 10488 11505 1260 49016 30505 17437 35792 41863
// descending B with smaller pb value: ./push_swap.a 33218 25885 40295 13935 48985 30463 10212 46638 1252 47686 11283 46066 17578 18514 35688 1767