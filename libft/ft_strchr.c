/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:18:11 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/23 17:21:29 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		i;

	chr = (char)c;
	i = 0;
	while (1)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (NULL);
}
