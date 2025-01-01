/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 19:27:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(void const *m1, void const *m2, size_t sz)
{
	unsigned char const	*s1 = (const unsigned char *)m1;
	unsigned char const	*s2 = (const unsigned char *)m2;

	while (sz-- > 0)
	{
		if (*s1++ != *s2++)
		{
			if (s1[-1] < s2[-1])
				return (-1);
			return (1);
		}
	}
	return (0);
}
