/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:20:30 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_calloc(size_t nmemb, size_t sz)
{
	void	*ptr;

	if (nmemb > 0 && sz > SIZE_MAX / nmemb)
		return (0);
	ptr = malloc(nmemb * sz);
	if (ptr)
		ft_memset(ptr, 0, nmemb * sz);
	return (ptr);
}
