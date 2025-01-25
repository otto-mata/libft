/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strjoin.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/25 12:19:30 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1sz;
	size_t	s2sz;
	size_t	sz;
	char	*s;

	if (!s1 || !s2)
		return (0);
	s1sz = ft_strlen(s1);
	s2sz = ft_strlen(s2);
	sz = s1sz + s2sz + 1;
	s = ft_calloc(sz, sizeof(char));
	if (!s)
		return (0);
	ft_memcpy(s, s1, s1sz);
	ft_memcpy(s + s1sz, s2, s2sz);
	return (s);
}

char	*ftgc_strjoin(char const *s1, char const *s2)
{
	size_t	s1sz;
	size_t	s2sz;
	size_t	sz;
	char	*s;

	if (!s1 || !s2)
		return (0);
	s1sz = ft_strlen(s1);
	s2sz = ft_strlen(s2);
	sz = s1sz + s2sz + 1;
	s = gc_calloc(sz, sizeof(char));
	if (!s)
		return (0);
	ft_memcpy(s, s1, s1sz);
	ft_memcpy(s + s1sz, s2, s2sz);
	return (s);
}
