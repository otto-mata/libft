/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 08:51:16 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	j;

	if (*s2 == 0)
		return ((char *)s1);
	if (*s1 == 0)
		return (0);
	while (n)
	{
		j = 0;
		while (s1[j] == s2[j] && s1[j] && j < n)
			j++;
		if (s2[j] == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
