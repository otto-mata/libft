/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   string_utils.c                                       ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 15:30:26 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/08 18:15:51 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"

void	*om_memmove(void *d, void const *s, size_t sz)
{
	char const	*src;
	char		*dest;
	char		*lasts;
	char		*lastd;

	src = s;
	if (!d && !s)
		return (d);
	dest = d;
	if (dest < src)
		while (sz--)
			*dest++ = *src++;
	else
	{
		lasts = (char *)(src + (sz - 1));
		lastd = dest + (sz - 1);
		while (sz--)
			*lastd-- = *lasts--;
	}
	return (d);
}

size_t	om_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*om_strcat(char *d, char const *s)
{
	size_t	ssz;
	size_t	dsz;

	if (!d || !s)
		return (0);
	ssz = om_strlen(s);
	dsz = om_strlen(d);
	om_memmove(d + dsz, s, ssz + 1);
	return (d);
}

void	__va_warn(char *s)
{
	if (!s)
		return ;
	write(2, s, om_strlen(s));
}
