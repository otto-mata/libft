/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:13 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t const	s1sz = ft_strlen(s1);
	size_t const	s2sz = ft_strlen(s2);
	size_t const	sz = s1sz + s2sz + 1;
	char			*s;

	s = ft_calloc(sz, sizeof(char));
	if (!s)
		return (0);
	ft_memcpy(s, s1, s1sz);
	ft_memcpy(s + s1sz, s2, s2sz);
	return (s);
}
