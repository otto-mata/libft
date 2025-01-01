/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 19:27:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(char const *s)
{
	size_t const	len = ft_strlen(s) + 1;
	char			*new;

	new = malloc(len * sizeof(char));
	if (!new)
		return (0);
	new[len - 1] = 0;
	return ((char *)ft_memcpy(new, s, len));
}
