/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcat.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:56:41 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *d, char const *s)
{
	size_t	ssz;
	size_t	dsz;

	if (!d || !s)
		return (0);
	ssz = ft_strlen(s);
	dsz = ft_strlen(d);
	ft_memcpy(d + dsz, s, ssz + 1);
	return (d);
}
