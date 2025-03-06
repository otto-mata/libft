/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strdup.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:58:55 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(char const *s)
{
	size_t	len;
	char	*new;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	new = malloc(len * sizeof(char));
	if (!new)
		return (0);
	new[len - 1] = 0;
	return ((char *)ft_memcpy(new, s, len));
}

char	*ftgc_strdup(char const *s)
{
	char	*new;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	new = gc_malloc(len * sizeof(char));
	if (!new)
		return (0);
	new[len - 1] = 0;
	return ((char *)ft_memcpy(new, s, len));
}
