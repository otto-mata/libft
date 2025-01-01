/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_list_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:15 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:40:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static char	*ft_join_free_s2(char const *s1, char *s2)
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

char	*va_list_parser(char flag, va_list args)
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
		return (ft_ltoh(va_arg(args, uint32_t), false));
	else if (flag == 'p')
		return (ft_join_free_s2("0x", ft_ltoh(va_arg(args, uint64_t), false)));
	else if (flag == 'X')
		return (ft_ltoh(va_arg(args, uint32_t), true));
	else if (flag == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}
