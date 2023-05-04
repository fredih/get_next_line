/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/04 21:13:05 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reorganize_buffer(char *buffer)
{
	size_t	char_index;
	char	*new_buffer;
	int		new_length;

	char_index = find_char(buffer, '\n');
	if (char_index > 0)
	{
		new_length = ft_strlen(&buffer[char_index]);
		new_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		ft_strlcpy(new_buffer, &buffer[char_index], new_length + 1);
		free(buffer);
		return (new_buffer);
	}
	else
		return (buffer);
}

char	*load_buffer(char *dest, char *buffer, size_t len)
{
	char	*result;
	char	*buffer_copy;

	buffer_copy = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	ft_strlcpy(buffer_copy, buffer, len + 1);
	result = ft_strjoin(dest, buffer_copy);
	free(dest);
	free(buffer_copy);
	return (result);
}

char *get_next_line(int fd)
{
	char			*current_line;
	static char		*buffer = NULL;
	int			read_result;
	size_t			char_index;

	current_line = ft_calloc(sizeof(char), 1);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	else
	{
		buffer = reorganize_buffer(buffer);
		if (buffer[0] != '\0')
		{
			char_index = find_char(buffer, '\n');
			if (char_index > 0)
			{
				current_line = load_buffer(current_line, buffer, char_index);
				return (current_line);
			}
			current_line = load_buffer(current_line, buffer, BUFFER_SIZE);
			free(buffer);
			buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
			return (current_line);
		}

	}
	read_result = read(fd, buffer, BUFFER_SIZE);
	while (read_result == BUFFER_SIZE)
	{
		char_index = find_char(buffer, '\n');
		if (char_index > 0)
		{
			current_line = load_buffer(current_line, buffer, char_index);
			return (current_line);
		}
		current_line = load_buffer(current_line, buffer, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_result = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_result > 0)
	{
		char_index = find_char(buffer, '\n');
		if (char_index > 0)
		{
			current_line = load_buffer(current_line, buffer, char_index);
			return (current_line);
		}
		current_line = load_buffer(current_line, buffer, read_result);
		free(buffer);
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		return (current_line);
	}
	if (BUFFER_SIZE == 1 && current_line[0] != '\0')
		return (current_line);
	free(current_line);
	current_line = NULL;
	free(buffer);
	buffer = NULL;
	return (current_line);
}

// char	*get_next_line(int fd)
// {
// 	char		*current_line;
// 	char		*line_copy;
// 	size_t		line_length;
// 	size_t		char_index;
// 	static char	*buffer = NULL;

// 	line_length = BUFFER_SIZE;
// 	current_line = malloc(sizeof(char) * (line_length + 1));
// 	if (BUFFER_SIZE > 1 && buffer && buffer[0] != 0)
// 	{
// 		char_index = find_char(buffer, '\n', BUFFER_SIZE);
// 		int a = find_2nd_char(&buffer[char_index], '\n', BUFFER_SIZE - char_index);
// 		ft_memcpy(current_line, &buffer[char_index],
// 			a);
// 	}
// 	if (!buffer)
// 	{
// 		buffer = malloc(sizeof(char) * BUFFER_SIZE);
// 		if (read(fd, current_line, BUFFER_SIZE) == 0)
// 		{
// 			free(current_line);
// 			return (NULL);
// 		}
// 	}
// 	line_copy = malloc(sizeof(char) * (line_length + 1));
// 	while (current_line[line_length - 1] != '\n')
// 	{
// 		ft_memcpy(line_copy, current_line, line_length);
// 		if (read(fd, &line_copy[line_length], BUFFER_SIZE) != BUFFER_SIZE)
// 			break ;
// 		char_index = find_char(line_copy, '\n', line_length + BUFFER_SIZE);
// 		if (char_index > 0)
// 		{
// 			ft_memcpy(current_line, line_copy, char_index + 1);
// 			if (BUFFER_SIZE > 1)
// 				ft_memcpy(buffer, &line_copy[char_index],
// 					(line_length + BUFFER_SIZE) - char_index);
// 			line_length = char_index + 1;
// 			break ;
// 		}
// 		free(current_line);
// 		current_line = malloc(sizeof(char) * (line_length + BUFFER_SIZE + 1));
// 		ft_memcpy(current_line, line_copy, line_length + BUFFER_SIZE + 1);
// 		line_length += BUFFER_SIZE;
// 		free(line_copy);
// 		line_copy = malloc(sizeof(char) * (line_length + BUFFER_SIZE));
// 	}
// 	current_line[line_length] = '\0';
// 	free(line_copy);
// 	return (current_line);
// }
