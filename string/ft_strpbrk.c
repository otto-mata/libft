/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strpbrk.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/31 17:57:48 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 14:01:20 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	const char	*src = s;
	char		*match;

	if (!s || !accept)
		return (0);
	while (*src)
	{
		match = ft_strchr(accept, *src);
		if (match)
			return (match);
		src++;
	}
	return (0);
}
