/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 17:35:07 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	return (ft_memcmp(s1, s2, ft_min(ft_strlen(s1), ft_strlen(s2))));
}
