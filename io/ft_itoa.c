/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_itoa.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 03:19:53 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static int	ft_uintlen(uint32_t n)
{
	int	sz;

	if (n == 0)
		return (1);
	sz = 0;
	while (n > 0)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

char	*ft_itoa_unsigned(uint32_t n)
{
	int const	nlen = ft_uintlen(n);
	int			i;
	int			digit;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(nlen + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < nlen)
	{
		digit = n % 10;
		str[i++] = '0' + digit;
		n /= 10;
	}
	ft_strrev(str);
	return (str);
}
