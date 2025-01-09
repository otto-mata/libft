/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf_int.h                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/14 16:26:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:36:41 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_H
# define FT_PRINTF_INT_H
# include "../llist/llist.h"
# include "../string/ft_string.h"
# include "io.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_formatter	t_formatter;

struct						s_formatter
{
	ssize_t					n;
	int						err;
	t_list					*flags;
};

int							ft_dprintf(int fd, char const *fmt, ...);
int							ft_display_formatted(char const *fmt,
								t_list *stats, int fd);
void						ft_parse_flags(char const *fmt, va_list args,
								t_formatter *fmtr);
void						ft_count_flags(char const *fmt, t_formatter *flags);
char						*va_list_parser(char flag, va_list args);
char						*ft_itoa_unsigned(uint32_t n);
char						*ft_ltoh(unsigned long n, int upper);
#endif
