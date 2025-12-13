/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:43:14 by brogaar           #+#    #+#             */
/*   Updated: 2025/12/07 02:20:57 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# define FT_PRINTF_H

int				ft_printf(const char *str, ...);
int				handlechr(va_list c);
int				handleint(va_list val);
int				handlestr(va_list str);
int				handlehexd(va_list ptr, int uppercase);
int				handlepercent(void);
int				handleptr(va_list ptr);
int				handleuint(va_list val);
int				handlenil(void);

// ---------- Util functions below ---------- //

int				numsize(int numb);
void			putuint(unsigned int nbr, int fd);
unsigned int	unumsize(unsigned int numb);

#endif