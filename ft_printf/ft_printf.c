/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:35:36 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 02:58:42 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isvalid(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'i'
		|| c == 'u' || c == 'd' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	handleformat(char c, va_list arg)
{
	int	bytes;

	bytes = 0;
	if (isvalid(c) != 1)
		ft_putstr_fd("Invalid input", 2);
	else
	{
		if (c == 'c')
			bytes = handlechr(arg);
		if (c == '%')
			bytes = handlepercent();
		if (c == 's')
			bytes = handlestr(arg);
		if (c == 'p')
			bytes = handleptr(arg);
		if (c == 'u')
			bytes = handleuint(arg);
		if (c == 'i' || c == 'd')
			bytes = handleint(arg);
		if (c == 'X')
			bytes = handlehexd(arg, 1);
		if (c == 'x')
			bytes = handlehexd(arg, 0);
	}
	return (bytes);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!isvalid(s[i]))
				return (1);
			bytes += handleformat(s[i], args);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			bytes++;
		}
		i++;
	}
	va_end(args);
	return (bytes);
}
