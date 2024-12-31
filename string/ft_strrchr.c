/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/20 12:10:21 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char			*ret;
	unsigned char	uc;

	ret = 0;
	uc = (unsigned char)c;
	if (uc == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == uc)
			ret = (char *)s;
		s++;
	}
	return (ret);
}
