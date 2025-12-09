/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:44:17 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/23 15:06:24 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*returnvalue;

	i = 0;
	returnvalue = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (returnvalue == NULL)
		return (NULL);
	while (s[i])
	{
		returnvalue[i] = s[i];
		i++;
	}
	if (ft_strlen(returnvalue) < i)
		return (NULL);
	else
	{
		returnvalue[i] = '\0';
		return (returnvalue);
	}
}
