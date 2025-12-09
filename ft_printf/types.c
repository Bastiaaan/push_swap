/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:46:05 by brogaar           #+#    #+#             */
/*   Updated: 2025/11/09 20:15:53 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlechr(va_list c)
{
	char	cast;

	cast = va_arg(c, int);
	write(1, &cast, 1);
	return (1);
}

int	handlestr(va_list str)
{
	char	*cast;

	cast = va_arg(str, char *);
	if (cast == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(cast, 1);
	return ((int)ft_strlen(cast));
}

int	handleint(va_list val)
{
	int	cast;

	cast = va_arg(val, int);
	ft_putnbr_fd(cast, 1);
	return (numsize(cast));
}

int	handleuint(va_list val)
{
	unsigned int	cast;

	cast = va_arg(val, unsigned int);
	putuint(cast, 1);
	return (unumsize(cast));
}

int	handlepercent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
