/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gcva_internals.h                                     ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 15:31:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:54:57 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCVA_INTERNALS_H
# define GCVA_INTERNALS_H
# include <stdlib.h>
# include <unistd.h>

void	*om_memmove(void *d, void const *s, size_t sz);
size_t	om_strlen(const char *s);
char	*om_strcat(char *d, char const *s);
void	__va_warn(char *s);
#endif
