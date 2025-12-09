/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:27 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/28 16:55:52 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	i = 0;
	if (!big)
		return (NULL);
	littlelen = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (len >= littlelen && big[i])
	{
		if (ft_strncmp(big + i, little, littlelen) == 0)
			return ((char *)(big + i));
		i++;
		len--;
	}
	return (NULL);
}
