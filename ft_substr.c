/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 14:17:26 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, size_t start, size_t sz)
{
	size_t const	len = ft_strlen(s);
	char			*subs;

	if (start <= len)
	{
		s += start;
		if (sz >= len)
			sz = len - start;
	}
	else
	{
		s += len;
		sz = 0;
	}
	subs = ft_calloc(sz + 1, sizeof(char));
	if (!subs)
		return (0);
	ft_strlcpy(subs, s, sz + 1);
	subs[sz] = 0;
	return (subs);
}
