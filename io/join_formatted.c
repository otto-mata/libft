/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   join_formatted.c                                     ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/06 21:27:09 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/07 07:24:12 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

static int	appnd_value(char const *s, t_list **f, char *dest)
{
	int	len;

	if (!s)
		return (-1);
	if (*(s + 1) == 'c')
	{
		ft_strcat(dest, (char *)((*f)->content));
		len = 1;
	}
	else
	{
		ft_strcat(dest, (char *)((*f)->content));
		len = ft_strlen((char *)((*f)->content));
	}
	*f = (*f)->next;
	return (len);
}

static int	appnd2c(char const *s, char *dest)
{
	ft_strcat(dest, s);
	ft_strcat(dest, (s + 1));
	return (2);
}

static int	catc(char *dest, char c)
{
	char	cs[2];

	cs[0] = c;
	cs[1] = 0;
	ft_strcat(dest, cs);
	return (1);
}

static int	extend(char *dest, t_list *f, char const *fmt)
{
	size_t	i;
	int		len;
	size_t	sz;

	sz = ft_strlen(fmt);
	i = 0;
	len = 0;
	while (i < sz)
	{
		if (fmt[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", fmt[i + 1]) && f)
				len += appnd_value(&fmt[i], &f, dest);
			else if (fmt[i + 1])
				len += appnd2c(&fmt[i], dest);
			else
				len += catc(dest, '%');
			i += 2;
		}
		else
			len += catc(dest, fmt[i++]);
	}
	return (len);
}

int	join_formatted(char const *fmt, t_list *f, char *s)
{
	int	len;

	if (!fmt || !f)
		return (-1);
	len = extend(s, f, fmt);
	if (!s)
		return (-1);
	return (len);
}
