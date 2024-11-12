/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 14:16:59 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *d, char const *s, size_t l)
{
	size_t const	ssz = ft_strlen(s);
	size_t			dsz;

	dsz = ft_strlen(d);
	if (l < dsz)
		dsz = l;
	if (dsz == l)
		return (l + ssz);
	if (ssz < l - dsz)
		ft_memcpy(d + dsz, s, ssz + 1);
	else
	{
		ft_memcpy(d + dsz, s, l - dsz - 1);
		d[l - 1] = 0;
	}
	return (dsz + ssz);
}
