/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:05 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/21 20:49:10 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*castdest;
	unsigned char	*castsrc;

	castdest = (unsigned char *)dest;
	castsrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			castdest[n] = castsrc[n];
		return (castdest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
// [12 12 (23 45] 43 56) before
// [12 12 (12 12] 12 12) from left to right (causes data loss) memcpy()
// [12 12 (12 12] 23 45) from right to left (prevents data loss) memmove()

// [23 45 (43 56] 43 56) 