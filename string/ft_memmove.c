/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 19:27:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *d, void const *s, size_t sz)
{
	char const	*src = s;
	char		*dest;
	char		*lasts;
	char		*lastd;

	if (!d && !s)
		return (d);
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
