/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:57:48 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 17:59:49 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	const char	*src = s;
	char		*match;
	
	while(*src)
	{
		match = ft_strchr(accept, *src);
		if (match)
			return (match);
		src++;
	}
	return (0);
}