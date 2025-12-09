/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:16 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/26 21:40:52 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlength;
	size_t	srclength;
	size_t	i;

	destlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	i = 0;
	if (destlength >= size)
		return (srclength + size);
	while ((destlength + i) < (size - 1) && src[i])
	{
		dst[destlength + i] = src[i];
		i++;
	}
	dst[destlength + i] = '\0';
	return (destlength + srclength);
}
