/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:35:06 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/06 10:41:45 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mega_free(int n, ...)
{
	va_list	args;
	void	*arg;
	int		i;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		arg = va_arg(args, void *);
		free(arg);
	}
	va_end(args);
	return ;
}
