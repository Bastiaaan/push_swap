/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:17:54 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/27 14:10:04 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*content;

	content = (unsigned char *)str;
	while (n > 0)
	{
		if (*content == (unsigned char)c)
			return (&(*content));
		content++;
		n--;
	}
	return (NULL);
}
