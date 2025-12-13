/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:12:10 by brogaar           #+#    #+#             */
/*   Updated: 2025/11/09 21:00:45 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlenil(void)
{
	ft_putstr_fd("(nil)", 1);
	return (5);
}

static void	strrev(char *src)
{
	size_t	i;
	size_t	end;
	char	temp;

	i = 0;
	end = ft_strlen(src) - 1;
	while (i < (end + 1) / 2)
	{
		temp = src[i];
		src[i] = src[end - i];
		src[end - i] = temp;
		i++;
	}
	temp = '\0';
}

static char	*hexastr(int uppercase)
{
	if (uppercase != 1)
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

int	handlehexd(va_list ptr, int uppercase)
{
	unsigned int	hexa;
	int				tmp;
	int				i;
	char			*hexalpha;
	char			result[16];

	i = 0;
	hexa = va_arg(ptr, unsigned int);
	hexalpha = hexastr(uppercase);
	if (hexa == 0)
		return (write(1, "0", 1));
	while (hexa != 0)
	{
		tmp = hexa % 16;
		hexa /= 16;
		if (tmp <= 15)
			result[i] = hexalpha[tmp];
		i++;
	}
	result[i] = '\0';
	strrev(result);
	ft_putstr_fd(result, 1);
	return (i);
}

int	handleptr(va_list ptr)
{
	size_t	hexa;
	int		tmp;
	int		i;
	char	*hexalpha;
	char	result[16];

	hexa = va_arg(ptr, size_t);
	hexalpha = "0123456789abcdef";
	if (hexa == 0x0)
		return (handlenil());
	i = 0;
	while (hexa != 0)
	{
		tmp = hexa % 16;
		hexa /= 16;
		if (tmp <= 15)
			result[i] = hexalpha[tmp];
		i++;
	}
	result[i] = '\0';
	strrev(result);
	ft_putstr_fd("0x", 1);
	i = i + 2;
	ft_putstr_fd(result, 1);
	return (i);
}
