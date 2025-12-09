/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:46:31 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/28 13:09:21 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	words(char const *s, char c)
{
	int	working;
	int	words;

	working = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && working == 0)
		{
			words++;
			working = 1;
		}
		else if (*s == c)
			working = 0;
		s++;
	}
	return (words);
}

static int	*getlens(char const *s, char c)
{
	int		elem;
	int		*lengths;
	char	tmp;
	size_t	i;

	elem = 0;
	i = 0;
	lengths = (int *)ft_calloc(words(s, c) + 1, sizeof(int));
	tmp = '\0';
	if (lengths == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c && tmp != c && tmp != '\0')
			elem++;
		else if (i == (ft_strlen(s) - 1) && tmp != c)
			lengths[elem]++;
		else if (s[i] != c)
			lengths[elem]++;
		i++;
		tmp = s[i - 1];
	}
	elem++;
	lengths[elem] = '\0';
	return (lengths);
}

static void	fillcontainer(char const *s, char **container, int *lengths, char c)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	while (lengths[index])
	{
		container[index] = ft_calloc((lengths[index]) + 1, sizeof(char));
		if (container[index] == NULL)
			free(container[index]);
		while (length < lengths[index])
		{
			if (*s != c)
			{
				container[index][length] = *s;
				length++;
			}
			s++;
		}
		container[index][length] = '\0';
		length = 0;
		index++;
	}
	container[index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		*mallocs;
	char	**container;

	mallocs = getlens(s, c);
	container = ft_calloc(words(s, c) + 1, sizeof(char *));
	if (container == NULL)
		return (NULL);
	else
	{
		fillcontainer(s, container, mallocs, c);
		free(mallocs);
	}
	return (container);
}
