/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 14:17:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	is_in_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

size_t	ft_first_non_set(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && is_in_charset(s1[i], set))
		i++;
	return (i);
}

static int	ft_recursive_trail_check(char const *s, char const *set)
{
	if (*s == 0)
		return (1);
	if (is_in_charset(*s, set))
		return (ft_recursive_trail_check(s + 1, set));
	return (0);
}

static size_t	ft_no_trail_len(char const *s, char const *set)
{
	size_t	l;

	l = 0;
	while (!ft_recursive_trail_check(&s[l], set))
		l++;
	return (l);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	dsz;
	size_t	i;
	size_t	firstchar;
	char	*s2;

	if (*s == '\0')
		return (ft_calloc(1, 1));
	firstchar = ft_first_non_set(s, set);
	dsz = ft_no_trail_len(s + firstchar, set);
	s2 = ft_calloc(dsz + 1, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < dsz)
	{
		s2[i] = (s + firstchar)[i];
		i++;
	}
	return (s2);
}
