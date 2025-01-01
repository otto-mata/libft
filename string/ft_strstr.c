/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:31:01 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	ssize_t	s1_len;
	ssize_t	s2_len;
	ssize_t	i;
	ssize_t	j;

	if (!s1 || !s2)
		return (0);
	s1_len = (ssize_t)ft_strlen(s1);
	s2_len = (ssize_t)ft_strlen(s2);
	if (!ft_strchr(s1, *s2))
		return (0);
	if (s2_len > s1_len)
		return (0);
	i = -1;
	while (++i <= s1_len - s2_len)
	{
		j = -1;
		while (++j < s2_len)
			if (s1[i + j] != s2[j])
				break ;
		if (j == s2_len)
			return ((char *)s1 + i);
	}
	return (0);
}
