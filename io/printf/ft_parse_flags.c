/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:10:46 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:40:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	ft_parse_flags(char const *fmt, va_list args, t_formatter *fmtr)
{
	size_t	j;
	t_list	*node;
	size_t	sz;

	if (!fmt)
		return ;
	sz = ft_strlen(fmt);
	j = 0;
	while (j < sz)
	{
		if (fmt[j] == '%')
		{
			node = ft_lstnew((void *)va_list_parser(fmt[++j], args));
			if (!node)
				return ;
			ft_lstadd_back(&fmtr->flags, node);
		}
		j++;
	}
}
