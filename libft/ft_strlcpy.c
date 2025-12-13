/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:19 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/24 07:31:31 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size > srclen)
	{
		dest = ft_memcpy(dest, src, srclen);
		dest[srclen] = '\0';
	}
	else if (size > 0)
	{
		dest = ft_memcpy(dest, src, size);
		dest[size - 1] = '\0';
	}
	return (srclen);
}
// size = size - 1