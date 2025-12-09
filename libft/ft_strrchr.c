/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:24 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/27 13:57:43 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*dest;
	char	cc;

	i = 0;
	dest = NULL;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			dest = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		dest = (char *)&s[i];
	return (dest);
}
