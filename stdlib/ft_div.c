/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:21:58 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 21:22:26 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

div_t	ft_div(int numer, int denom)
{
	div_t	result;

	result.quot = numer / denom;
	result.rem = numer % denom;
	return (result);
}
