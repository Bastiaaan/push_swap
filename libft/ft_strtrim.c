/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:42:08 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/28 13:17:17 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimable(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpys1;
	int		start;
	int		end;

	start = 0;
	end = (ft_strlen(s1));
	if (*s1 == '\0')
	{
		cpys1 = ft_calloc(1, sizeof(char));
		return (cpys1);
	}
	while (s1[start] && istrimable(set, s1[start]))
		start++;
	if (start >= end)
	{
		cpys1 = ft_calloc(1, sizeof(char));
		return (cpys1);
	}
	while (s1[end - 1] && istrimable(set, s1[end - 1]))
		end--;
	cpys1 = ft_substr(s1, start, (end - start));
	return (cpys1);
}
