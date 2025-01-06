/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sprintf.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/06 21:04:19 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/06 23:08:02 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

static void	agg_fmt_var(char const *fmt, va_list args, t_formatter *fmtr)
{
	size_t	j;
	t_list	*node;
	size_t	sz;

	sz = ft_strlen(fmt);
	j = 0;
	while (j < sz)
	{
		if (fmt[j] == '%')
		{
			node = ft_lstnew((void *)parse_variadic(fmt[++j], args));
			if (!node)
				return ;
			ft_lstadd_back(&fmtr->flags, node);
		}
		j++;
	}
}

int	ft_sprintf(char *s, char const *fmt, ...)
{
	va_list		args;
	t_formatter	formatter;
	int			len;

	if (!fmt || !s)
		return (-1);
	va_start(args, fmt);
	formatter.err = 0;
	formatter.n = 0;
	formatter.flags = 0;
	ft_count_flags(fmt, &formatter);
	agg_fmt_var(fmt, args, &formatter);
	len = join_formatted(fmt, formatter.flags, s);
	va_end(args);
	ft_lstclear(&(formatter.flags), free);
	return (len);
}
