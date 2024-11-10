/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/10 23:54:07 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(char const *s, int c)
{
	char	*ret;

	ret = 0;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	return (ret);
}
