/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   replace.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 05:42:04 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:42:23 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*replace(char *in, char *sub, char *by)
{
	size_t	sub_sz;
	size_t	final_sz;
	char	*ret;
	char	*substart;

	if (!in || !sub)
		return (0);
	substart = ft_strstr(in, sub);
	if (!substart)
		return (ft_strdup(in));
	sub_sz = ft_strlen(sub);
	if (!by)
		by = "";
	final_sz = ft_strlen(in) - sub_sz + ft_strlen(by);
	ret = ft_calloc(final_sz + 1, sizeof(char));
	if (!ret)
		return (0);
	ft_strncpy(ret, in, (size_t)(substart - in));
	ft_strcat(ret, by);
	ft_strcat(ret, (char *)(substart + sub_sz));
	return (ret);
}
