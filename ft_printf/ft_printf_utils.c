/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:08:16 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 03:15:20 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putuint(unsigned int nbr, int fd)
{
	char	c;

	if (nbr <= 9)
	{
		c = (nbr + 48);
		ft_putchar_fd(c, fd);
		c = '\0';
	}
	else
	{
		putuint(nbr / 10, fd);
		putuint(nbr % 10, fd);
	}
}

int	numsize(int numb)
{
	int		size;
	long	tmp;
	long	cast;

	size = 1;
	tmp = 0;
	cast = numb;
	if (cast < 0)
	{
		cast *= -1;
		size++;
	}
	while (cast > 0)
	{
		cast /= 10;
		tmp = cast % 10;
		if (cast > 0 || tmp > 0)
			size++;
	}
	return (size);
}

unsigned int	unumsize(unsigned int numb)
{
	int		size;
	long	tmp;

	size = 1;
	tmp = 0;
	while (numb > 0)
	{
		numb /= 10;
		tmp = numb % 10;
		if (numb > 0 || tmp > 0)
			size++;
	}
	return (size);
}
