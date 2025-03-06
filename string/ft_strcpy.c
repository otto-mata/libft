/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcpy.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:57:42 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcpy(char *d, char const *s)
{
	size_t	src_len;

	if (!s || !d)
		return (0);
	src_len = ft_strlen(s);
	ft_memcpy(d, s, src_len + 1);
	return (d);
}
