/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:29:32 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/02 00:50:16 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include "libft.h"
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>



static char	toupper_wrapper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

static char	tolower_wrapper(unsigned int i, char c)
{
	(void)i;
	return (ft_tolower(c));
}
static void	void_toupper_wrapper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

static void	void_tolower_wrapper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_tolower(*c);
}

static void	seeding_magic(void)
{
	void		*urandom;
	int const	fd = open("/dev/urandom", O_RDONLY);

	urandom = calloc(128, sizeof(uint8_t));
	if (!fd)
		return (srand(time(0)));
	if (read(fd, urandom, 128) != 128)
		return (srand(time(0)));
	srand(ft_hashstr(urandom, 128));
	free(urandom);
}

static char	*random_string(size_t sz)
{
	char	*s;
	size_t	i;
	char	c;

	s = calloc(sz + 1, sizeof(char));
	if (!s)
		return (0);
	i = 0;
	c = 0;
	while (i < sz)
	{
		while (!isalnum(c))
			c = rand() % (122 + 1 - 48) + 48;
		s[i] = c;
		c = 0;
		i++;
	}
	return (s);
}

int	main(void)
{
	char *s;
	while ((s = get_next_line(0)))
	{
		ft_printf("%s",s);
	}
}
