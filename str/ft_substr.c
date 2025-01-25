/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_substr.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/25 12:26:24 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ssz;
	size_t	newsz;
	char	*subs;

	if (!s)
		return (0);
	ssz = ft_strlen(s);
	if (start > ssz)
		return (ft_strdup(""));
	newsz = ssz - start;
	if (newsz > len)
		newsz = len;
	subs = ft_calloc(newsz + 1, sizeof(char));
	if (!subs)
		return (0);
	i = 0;
	while (i < newsz)
		subs[i++] = s[start++];
	return (subs);
}

char	*ftgc_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ssz;
	size_t	newsz;
	char	*subs;

	if (!s)
		return (0);
	ssz = ft_strlen(s);
	if (start > ssz)
		return (ftgc_strdup(""));
	newsz = ssz - start;
	if (newsz > len)
		newsz = len;
	subs = gc_calloc(newsz + 1, sizeof(char));
	if (!subs)
		return (0);
	i = 0;
	while (i < newsz)
		subs[i++] = s[start++];
	return (subs);
}
