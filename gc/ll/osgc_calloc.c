/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:29 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/19 08:34:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_calloc(size_t nmemb, size_t sz)
{
	void	*mem;

	if (nmemb > 0 && sz > SIZE_MAX / nmemb)
		return (NULL);
	mem = osgc_malloc(nmemb * sz);
	if (mem)
		otto_bzero(mem, nmemb * sz);
	return (mem);
}
