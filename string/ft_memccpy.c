/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:13:42 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 19:27:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void *ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char const	*src = s;
	unsigned char		*dest;

	if (!d && !s)
		return (d);
	dest = d;
	while (n--)
	{
		*dest++ = *src++;
		if (*(dest - 1) == (unsigned char)c)
			return (dest);
	}
	return (0);
}