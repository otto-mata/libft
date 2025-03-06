/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strnlen.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 14:00:47 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strnlen(char const *s, size_t maxlen)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len > maxlen)
		return (maxlen);
	return (len);
}
