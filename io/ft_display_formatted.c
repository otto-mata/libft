/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_display_formatted.c                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/19 17:11:44 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:36:50 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

static int	ft_print_value(char const *s, t_list **f, int fd)
{
	int	len;

	if (*(s + 1) == 'c')
		len = ft_putchar_fd(*(char *)((*f)->content), fd);
	else
		len = ft_putstr_fd((char *)((*f)->content), fd);
	*f = (*f)->next;
	return (len);
}

static int	appnd2c(char const *s, int fd)
{
	return (ft_putchar_fd(*s, fd) + ft_putchar_fd(*(s + 1), fd));
}

int	ft_display_formatted(char const *fmt, t_list *f, int fd)
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
				len += ft_print_value(&fmt[i], &f, fd);
			else if (fmt[i + 1])
				len += appnd2c(&fmt[i], fd);
			else
				len += ft_putchar_fd('%', fd);
			i += 2;
		}
		else
			len += ft_putchar_fd(fmt[i++], fd);
	}
	return (len);
}
