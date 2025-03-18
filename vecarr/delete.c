/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   delete.c                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:09:10 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

int	va_delete(t_vecarr *v, long index)
{
	if (index >= v->len)
		return (-1);
	if (index < 0)
		index = v->len + index;
	free(v->data[index]);
	om_memmove(v->data + index, v->data + index + 1, (v->len - index - 1)
		* sizeof(void **));
	v->len--;
	return (0);
}
