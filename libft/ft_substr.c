/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:21:29 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/27 14:35:05 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	determinesize(char const *s, unsigned int start, size_t len)
{
	int	mallsize;
	int	slength;

	mallsize = 0;
	slength = ft_strlen(s);
	if (len >= (slength - start))
		mallsize = slength - start;
	else
		mallsize = len;
	return (mallsize + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*container;

	i = 0;
	if (*s == '\0' || start >= ft_strlen(s))
	{
		container = ft_calloc(1, sizeof(char));
		return (container);
	}
	if (start >= ft_strlen(s))
		start -= ft_strlen(s);
	container = ft_calloc(determinesize(s, start, len), sizeof(char));
	if (container == NULL)
		return (NULL);
	while (s[i + start] && i < len)
	{
		container[i] = s[i + start];
		i++;
	}
	container[i] = '\0';
	return (container);
}
