/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 20:17:31 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	ft_intlen(int n)
{
	int	sz;

	if (n == INT_MIN)
		return (10);
	if (n == 0)
		return (1);
	sz = 0;
	n = ft_abs(n);
	while (n > 0)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

char	*ft_itoa(int n)
{
	int const	sign = (n < 0);
	int const	nlen = ft_intlen(n);
	int			i;
	int			digit;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(nlen + sign + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < nlen)
	{
		digit = n % 10;
		str[i++] = '0' + ft_abs(digit);
		n /= 10;
	}
	if (sign)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
