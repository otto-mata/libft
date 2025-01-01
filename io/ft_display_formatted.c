/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_formatted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:44 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:42:51 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static int	ft_print_value(char const *s, t_list **f)
{
	int	len;

	if (*(s + 1) == 'c')
		len = ft_putchar_fd(*(char *)((*f)->content), 1);
	else
		len = ft_putstr_fd((char *)((*f)->content), 1);
	*f = (*f)->next;
	return (len);
}

static int	put2c(char const *s)
{
	return (ft_putchar_fd(*s, 1) + ft_putchar_fd(*(s + 1), 1));
}

int	ft_display_formatted(char const *fmt, t_list *f)
{
	size_t	i;
	int		len;
	size_t	sz;

	if (!fmt)
		return (-1);
	sz = ft_strlen(fmt);
	i = 0;
	len = 0;
	while (i < sz)
	{
		if (fmt[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", fmt[i + 1]) && f)
				len += ft_print_value(&fmt[i], &f);
			else if (fmt[i + 1])
				len += put2c(&fmt[i]);
			else
				len += ft_putchar_fd('%', 1);
			i += 2;
		}
		else
			len += ft_putchar_fd(fmt[i++], 1);
	}
	return (len);
}
