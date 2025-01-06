/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parse_variadic.c                                     ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/06 21:23:28 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/06 22:09:44 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

static char	*ft_format_pointer(char const *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (ft_strncmp(ret, "0x0", ft_strlen(ret)) == 0)
	{
		free(ret);
		ret = ft_strdup("(nil)");
	}
	free(s2);
	return (ret);
}

static char	*ft_parse_string(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

static char	*ft_parse_char(char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = 0;
	return (ft_strdup(buf));
}

char	*parse_variadic(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_parse_char(va_arg(args, int) % 256));
	else if (flag == 's')
		return (ft_parse_string(va_arg(args, char *)));
	else if (flag == 'u')
		return (ft_itoa_unsigned(va_arg(args, uint32_t)));
	else if (flag == 'i' || flag == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (flag == 'x')
		return (ft_ltoh(va_arg(args, uint32_t), 0));
	else if (flag == 'p')
		return (ft_format_pointer("0x", ft_ltoh(va_arg(args, uint64_t), 0)));
	else if (flag == 'X')
		return (ft_ltoh(va_arg(args, uint32_t), 1));
	else if (flag == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}
