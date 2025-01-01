/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:20:45 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:20:02 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_stpncpy(char *d, char const *s, size_t n)
{
	const size_t	src_len = ft_strlen(s);
	char			*dest;
	char			*src;

	dest = d;
	src = (char *)s;
	while (*src && n--)
		*dest++ = *src++;
	while (n--)
		*dest++ = 0;
	if (src_len >= n)
		return (d + n);
	return (d + src_len);
}
