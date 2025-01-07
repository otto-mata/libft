/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putendl_fd.c                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/07 07:24:16 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

ssize_t	ft_putendl_fd(char const *s, int fd)
{
	ssize_t	ret;

	ret = ft_putstr_fd(s, fd);
	ret += ft_putchar_fd('\n', fd);
	return (ret);
}
