/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/10 23:05:12 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memmove(void *d, void const *s, size_t sz)
{
	char const *src = s;
	char *dest;
	char *lasts;
	char *lastd;

	dest = d;
	if (dest < src)
		ft_memcpy(d, s, sz);
	else
	{
		lasts = (char*)(src + (sz - 1));
		lastd = dest + (sz - 1);
		while (sz--)
			*lastd-- = *lasts--;
	}
	return (d);
}
