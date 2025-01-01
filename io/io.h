/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:21:44 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:43:28 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# include "../stdlib/ft_stdlib.h"
# include "../str/str.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Writes a character to a file descriptor.
 *
 * @param c The character to write.
 * @param fd The file descriptor.
 */
ssize_t	ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 */
ssize_t	ft_putstr_fd(char const *s, int fd);

/**
 * @brief Writes a string with a newline to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 */
ssize_t	ft_putendl_fd(char const *s, int fd);

/**
 * @brief Writes an integer to a file descriptor.
 *
 * @param n The integer to write.
 * @param fd The file descriptor.
 */
void	ft_putnbr_fd(int n, int fd);

char	*get_next_line(int fd);

int		ft_printf(char const *fmt, ...);
#endif