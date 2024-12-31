/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:20:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 17:27:58 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_stpncpy(char *d, char const *s, size_t n)
{
	const size_t	src_len = ft_strlen(s);
	char			*dest;
	char			*src;

	*dest = d;
	*src = s;
	while (*src && n--)
		*dest++ = *src++;
	while (n--)
		*dest++ = 0;
	if (src_len >= n)
		return (d + n);
	return (d + src_len);
}
