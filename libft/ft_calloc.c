/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:41:08 by brogaar           #+#    #+#             */
/*   Updated: 2025/10/27 19:07:52 by brogaar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	capacity;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (INT_MAX / size))
		mem = malloc(1);
	else
	{
		capacity = (nmemb * size);
		mem = malloc(capacity);
	}
	if (mem == NULL)
		return (NULL);
	else
		ft_memset(mem, 0, capacity);
	return (mem);
}
// 100 > 50