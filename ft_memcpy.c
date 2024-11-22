/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/22 12:01:09 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, void const *s, size_t sz)
{
	unsigned char const	*src = s;
	unsigned char		*dest;

	if (!d && !s)
		return (d);
	dest = d;
	while (sz--)
		*dest++ = *src++;
	return (d);
}
