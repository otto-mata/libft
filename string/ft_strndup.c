/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strndup.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 14:00:22 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strndup(char const *s, size_t n)
{
	size_t	len;
	char	*new;

	if (!s)
		return (0);
	len = ft_min(ft_strlen(s), n) + 1;
	new = malloc(len * sizeof(char));
	if (!new)
		return (0);
	new[len - 1] = 0;
	return ((char *)ft_memcpy(new, s, len));
}
