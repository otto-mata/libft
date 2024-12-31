/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:20:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 17:21:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_stpcpy(char *d, char const *s)
{
	size_t const	src_len = ft_strlen(s);


	ft_memcpy(d, s, src_len + 1);
	return (d + src_len);
}
