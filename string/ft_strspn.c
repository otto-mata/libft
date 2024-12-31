/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:38:49 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 17:43:42 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*src = s;
	size_t		count;

	count = 0;
	while (*src)
	{
		if (ft_strchr(accept, *src))
			count++;
		else
			return (count);
		src++;
	}
	return (count);
}