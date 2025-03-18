/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:34:09 by ottomata          #+#    #+#             */
/*   Updated: 2025/03/09 01:35:32 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

size_t	pow_2_up_to_exp(size_t n, size_t exponent)
{
	const size_t	power_of_2 = (1 << exponent) - 1;

	return ((n + power_of_2) & (~power_of_2));
}

void	ft_bzero(void *mem, size_t sz)
{
	unsigned char	*uc_mem;

	if (!mem)
		return ;
	uc_mem = (unsigned char *)mem;
	while (sz--)
		*uc_mem++ = 0;
}

void	*ft_memcpy(void *d, void const *s, size_t sz)
{
	unsigned char const	*src;
	unsigned char		*dest;

	src = s;
	if (!d && !s)
		return (d);
	dest = d;
	while (sz--)
		*dest++ = *src++;
	return (d);
}

void	*ft_memmove(void *d, void const *s, size_t sz)
{
	char	*src;
	char	*dest;
	char	*lasts;
	char	*lastd;

	if (!d && !s)
		return (d);
	src = (char *)s;
	dest = d;
	if (dest < src)
		ft_memcpy(d, s, sz);
	else
	{
		lasts = (char *)(src + (sz - 1));
		lastd = dest + (sz - 1);
		while (sz--)
			*lastd-- = *lasts--;
	}
	return (d);
}
