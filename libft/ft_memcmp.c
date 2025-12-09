/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:17:57 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/24 07:29:13 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casts1;
	unsigned char	*casts2;

	casts1 = (unsigned char *) s1;
	casts2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*casts1 != *casts2)
			return (*casts1 - *casts2);
		casts1++;
		casts2++;
		n--;
	}
	return (0);
}
