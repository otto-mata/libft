/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_ctype.h                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 20:01:54 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 03:18:10 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_iscntrl(int c);
int	ft_isdigit(int c);
int	ft_isgraph(int c);
int	ft_islower(int c);
int	ft_isprint(int c);
int	ft_ispunct(int c);
int	ft_isspace(int c);
int	ft_isupper(int c);
int	ft_isxdigit(int c);
int	ft_isascii(int c);
int	ft_isblank(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
#endif
