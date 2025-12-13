/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:45 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/28 13:08:44 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	mallocsize(long numb)
{
	int		size;
	long	tmp;

	size = 1;
	tmp = 0;
	if (numb < 0)
	{
		numb *= -1;
		size++;
	}
	while (numb > 0)
	{
		numb /= 10;
		tmp = numb % 10;
		if (numb > 0 || tmp > 0)
			size++;
	}
	return (size);
}

static char	*fillstr(char *dst, long src, int len, int sign)
{
	int	index;

	if (sign < 0)
		index = 1;
	else
		index = 0;
	while (src >= 0 && len > index)
	{
		if (sign < 0)
			dst[len - index] = (char)((src % 10) + 48);
		else
			dst[len - 1 - index] = (char)((src % 10) + 48);
		src /= 10;
		index++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*container;	
	int		sign;
	long	nbr;

	nbr = n;
	sign = 0;
	length = mallocsize(nbr);
	container = ft_calloc(length + 1, sizeof(char));
	if (container == NULL)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		nbr *= -1;
		container[0] = '-';
	}
	fillstr(container, nbr, length, sign);
	container[length] = '\0';
	return (container);
}
//increase mandatory to create space for - sign. at rule 44.