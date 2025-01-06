/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   join_formatted.c                                     ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/06 21:27:09 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/06 22:09:37 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

static int	appnd_value(char const *s, t_list **f, t_string *estr)
{
	int	len;
	int	i;

	if (!s)
		return (-1);
	if (*(s + 1) == 'c')
	{
		expstr_append(estr, *(char *)((*f)->content));
		len = 1;
	}
	else
	{
		i = -1;
		while (((char *)((*f)->content))[++i])
			expstr_append(estr, ((char *)((*f)->content))[i]);
		len = ft_strlen((char *)((*f)->content));
	}
	*f = (*f)->next;
	return (len);
}

static int	appnd2c(char const *s, t_string *estr)
{
	expstr_append(estr, *s);
	expstr_append(estr, *(s + 1));
	return (2);
}

static int extend(t_string *es, t_list *f, char const *fmt)
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
				len += appnd_value(&fmt[i], &f, es);
			else if (fmt[i + 1])
				len += appnd2c(&fmt[i], es);
			else
				len += expstr_append(es, '%');
			i += 2;
		}
		else
			len += expstr_append(es, fmt[i++]);
	}
	return (len);
}

int	join_formatted(char const *fmt, t_list *f, char *s)
{
	int		len;
	t_string *es;

	if (!fmt || !f)
		return (-1);		
	es = expstr_new(1);
	len = extend(es, f, fmt);
	free(s);
	s = ft_strdup(es->content);
	if (!s)
		return (-1);
	expstr_destroy(&es);
	return (len);
}
