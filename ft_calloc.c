/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 11:07:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_calloc(size_t nmemb, size_t sz)
{
	void *ptr;

	if (nmemb == 0 || sz == 0)
	{
		nmemb = 1;
		sz = 1;
	}
	ptr = malloc(nmemb * sz);
	if (ptr)
		ft_bzero(ptr, nmemb * sz);
	return (ptr);
}
