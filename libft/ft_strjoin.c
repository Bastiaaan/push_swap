/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:50:04 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/18 17:19:55 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i1;
	size_t	i2;
	size_t	retlen;

	i1 = 0;
	i2 = 0;
	retlen = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i1])
	{
		str[retlen] = s1[i1];
		retlen++;
		i1++;
	}
	while (s2[i2])
	{
		str[retlen] = s2[i2];
		retlen++;
		i2++;
	}
	str[retlen] = '\0';
	return (str);
}
