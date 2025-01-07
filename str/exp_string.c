/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   exp_string.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/30 18:17:30 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/07 07:22:16 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static void	*ft_realloc(void *mem, size_t old_sz, size_t new_sz)
{
	void	*nmem;
	size_t	sz;

	nmem = malloc(new_sz);
	if (!nmem)
		return (0);
	if (!mem)
		return (nmem);
	if (new_sz < old_sz)
		sz = new_sz;
	else
		sz = old_sz;
	while (sz--)
		((unsigned char *)nmem)[sz] = ((unsigned char *)mem)[sz];
	return (nmem);
}

t_string	*expstr_new(unsigned long start_sz)
{
	t_string	*str;

	str = malloc(sizeof(t_string));
	if (!str)
		return (0);
	str->len = 1;
	str->sz = start_sz;
	str->content = ft_calloc(str->sz, sizeof(char));
	if (!str->content)
		return (0);
	return (str);
}

int	expstr_append(t_string *str, char val)
{
	while (str->sz / 2 < (str->len + 1))
	{
		str->content = ft_realloc(str->content, str->sz, str->sz * 2);
		str->sz *= 2;
	}
	if (!str)
		return (0);
	str->content[str->len - 1] = val;
	str->content[str->len] = 0;
	str->len++;
	return (1);
}

void	expstr_destroy(t_string **str)
{
	free((*str)->content);
	free(*str);
	*str = 0;
}
