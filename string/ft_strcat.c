/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcat.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 12:52:07 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *d, char const *s)
{
	size_t const	ssz = ft_strlen(s);
	size_t			dsz;

	dsz = ft_strlen(d);
	ft_memcpy(d + dsz, s, ssz + 1);
	return (d);
}
