/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 02:03:50 by brogaar           #+#    #+#             */
/*   Updated: 2026/01/26 17:23:08 by brogaar          ###   ########.fr       */
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
		return (1);
	}
	else if (argc == 2 && ft_strchr(argv[1], 32) != NULL)
		list_a = handlebigargv(argv[1]);
	else
		list_a = handleargv(argv);
	// if (!ft_lstunique(&list_a))
	// {
	// 	ft_printf("Error\n");
	// 	return (1);
	// }
	list_b = NULL;
	set_rankings(list_a);
	run(list_a, list_b);
	free_list(list_a);
	free_list(list_b);
	return (0);
}
// testing already sorted list: 4 5 234 310 400 673 824
// make re && ./push_swap.a 27052 2115 28406 25393 3780 34829 38903 7304 33672 20805 38466 46141 29931 40997 24240 27642 36607 8915 46758 39083 15256 44636 26895 2780 45849 16674 25857 24018 14041 44492 4175 14253 4573 18544 3320 112 1466 24509 44878 45155 14368 1164 19786 23046 35559 46178 15107 47244 30874 17841 -- normal test
// make debug && gdb ./push_swap.test -- debug test with gdb47 5 89 16 53 71 8 94 30 61
// ./push_swap.a 44865 39502 15069 29203 15669 44209 46919 10488 11505 1260 49016 30505 17437 35792 41863
// descending B with smaller pb value: ./push_swap.a 33218 25885 40295 13935 48985 30463 10212 46638 1252 47686 11283 46066 17578 18514 35688 1767