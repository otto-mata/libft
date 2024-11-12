/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 10:36:27 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_count_words(char *str, char c)
{
	size_t	words_found;
	size_t	i;

	words_found = 0;
	i = 0;
	while (str[i])
	{
		if (c != str[i] && (i == 0 || c == str[i - 1]))
			words_found++;
		i++;
	}
	return (words_found);
}

static char	*ft_strdup_word(char *s, char c)
{
	size_t	src_len;
	size_t	i;
	char	*dest;

	src_len = -1;
	while ((!(s[++src_len] == c)) && s[src_len])
		;
	dest = malloc((src_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (++i < src_len)
		dest[i] = s[i];
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	word_count;
	size_t	i;
	size_t	array_i;
	size_t	src_len;

	word_count = ft_count_words((char *)s, c) + 1;
	str_array = malloc(word_count * sizeof(char *));
	if (!str_array)
		return (0);
	src_len = ft_strlen(s);
	i = -1;
	array_i = 0;
	while (++i < src_len)
	{
		if (c == s[i])
			continue ;
		str_array[array_i] = ft_strdup_word((char *)(s + i), c);
		i += ft_strlen(str_array[array_i]);
		array_i++;
	}
	str_array[array_i] = 0;
	return (str_array);
}
