/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:24 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:16:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

char	*ft_join_and_free_s1(char *s1, char *s2)
{
	char	*temp;

	if (!s1 || !s2)
		return (0);
	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*shift_left(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*extract_line_from(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + !!(buffer[i] == '\n'), sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_from_fd(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[byte_read] = 0;
		res = ft_join_and_free_s1(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0)
		{
			free(buffer[fd]);
			buffer[fd] = 0;
		}
		return (0);
	}
	buffer[fd] = read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = extract_line_from(buffer[fd]);
	buffer[fd] = shift_left(buffer[fd]);
	return (line);
}

/* #include <stdio.h>
int	main(int argc, char const *argv[])
{
	int		fd;
	int		lines;
	int		start_lines;
	char	*s;

	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		start_lines = atoi(argv[2]);
	else
		start_lines = 5;
	lines = 0;
	while (lines < start_lines)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		lines++;
	}
	return (0);
}
 */