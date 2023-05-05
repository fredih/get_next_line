/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/05 15:40:58 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	reorganize_buffer(char *buffer)
{
	size_t	char_index;
	size_t	len;
	size_t	i;

	char_index = find_char(buffer, '\n');
	len = ft_strlen(&buffer[char_index]);
	if (char_index > 0)
	{
		i = 0;
		while (i < len)
		{
			buffer[i] = buffer[char_index + i];
			i++;
		}
		while (i < BUFFER_SIZE + 1)
		{
			buffer[i] = '\0';
			i++;
		}
	}
}

char	*load_buffer(char *dest, char *buffer, size_t len)
{
	char	*result;
	char	*buffer_copy;

	buffer_copy = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_memset(buffer_copy, '\0', sizeof(char) * (BUFFER_SIZE + 1));
	ft_strlcpy(buffer_copy, buffer, len + 1);
	result = ft_strjoin(dest, buffer_copy);
	free(dest);
	free(buffer_copy);
	return (result);
}

char	*process_buffer(char *current_line, char *buffer)
{
	size_t	char_index;

	char_index = find_char(buffer, '\n');
	if (char_index > 0)
	{
		current_line = load_buffer(current_line, buffer, char_index);
		return (current_line);
	}
	current_line = load_buffer(current_line, buffer, BUFFER_SIZE);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	return (current_line);
}

char	*my_read(int fd, char *current_line, char *buffer)
{
	int		read_result;

	read_result = read(fd, buffer, BUFFER_SIZE);
	while (read_result == BUFFER_SIZE)
	{
		if (find_char(buffer, '\n') > 0)
			return (load_buffer(current_line, buffer, find_char(buffer, '\n')));
		current_line = load_buffer(current_line, buffer, BUFFER_SIZE);
		ft_memset(buffer, '\0', sizeof(char) * (BUFFER_SIZE + 1));
		read_result = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_result > 0)
		return (process_buffer(current_line, buffer));
	if (current_line[0] != '\0')
		return (current_line);
	free(current_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*current_line;
	static char		buffer[BUFFER_SIZE + 1];
	size_t			char_index;

	if (BUFFER_SIZE == 0)
		return (NULL);
	current_line = malloc(sizeof(char) * 1);
	ft_memset(current_line, '\0', sizeof(char) * 1);
	reorganize_buffer(buffer);
	if (buffer[0] != '\0')
	{
		char_index = find_char(buffer, '\n');
		if (char_index > 0)
		{
			current_line = load_buffer(current_line, buffer, char_index);
			return (current_line);
		}
		current_line = load_buffer(current_line, buffer, BUFFER_SIZE);
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	}
	current_line = my_read(fd, current_line, buffer);
	return (current_line);
}
