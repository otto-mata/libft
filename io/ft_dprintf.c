/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_dprintf.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 20:01:13 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 13:00:03 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"
#include "io.h"

int	ft_dprintf(int fd, char const *fmt, ...)
{
	va_list		args;
	t_formatter	fmtr;
	int			len;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	fmtr.err = 0;
	fmtr.flags = 0;
	ft_count_flags(fmt, &fmtr);
	if (fmtr.n < 0)
		return (-1);
	ft_parse_flags(fmt, args, &fmtr);
	len = ft_display_formatted(fmt, fmtr.flags, fd);
	if (fmtr.err || len < 0)
		len = -1;
	ft_lstclear(&fmtr.flags, free);
	va_end(args);
	return (len);
}

int	ft_printf(char const *fmt, ...)
{
	va_list		args;
	t_formatter	fmtr;
	int			len;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	fmtr.err = 0;
	fmtr.flags = 0;
	ft_count_flags(fmt, &fmtr);
	if (fmtr.n < 0)
		return (-1);
	ft_parse_flags(fmt, args, &fmtr);
	len = ft_display_formatted(fmt, fmtr.flags, 1);
	if (fmtr.err || len < 0)
		len = -1;
	ft_lstclear(&fmtr.flags, free);
	va_end(args);
	return (len);
}
