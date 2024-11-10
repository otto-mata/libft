/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 11:07:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}