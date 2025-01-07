/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gnl.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:58:24 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/07 07:18:23 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

static char	*ft_join_and_free_s1(char *s1, char *s2)
{
	char	*temp;

	if (!s1 || !s2)
		return (0);
	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

static char	*shift_left(char *buffer)
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

static char	*extract_line_from(char *buffer)
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

static char	*read_from_fd(int fd, char *res)
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
	static int	last_fd = 0;
	char		*line;

	if (fd == -2)
		return (free(buffer[last_fd]), (char *) 0);
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0)
		{
			free(buffer[fd]);
			buffer[fd] = 0;
		}
		return (0);
	}
	last_fd = fd;
	buffer[fd] = read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = extract_line_from(buffer[fd]);
	buffer[fd] = shift_left(buffer[fd]);
	return (line);
}
