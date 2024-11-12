/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 12:12:52 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *d, char const *s, size_t l)
{
	size_t const	srclen = ft_strlen(s);

	if (srclen < l)
		ft_memcpy(d, s, srclen + 1);
	else if (l != 0)
	{
		ft_memcpy(d, s, l - 1);
		d[l - 1] = '\0';
	}
	return (srclen);
}
