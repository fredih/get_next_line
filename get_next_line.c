/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/03 14:31:15 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*line_copy;
	size_t		line_length;
	static char	*buffer = NULL;
	size_t		i;

	if (buffer != NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	line_length = BUFFER_SIZE;
	current_line = malloc(sizeof(char) * (line_length + 1));
	if (read(fd, buffer, BUFFER_SIZE) == 0)
	{
		free(current_line);
		return (NULL);
	}
	line_copy = malloc(sizeof(char) * (line_length + BUFFER_SIZE));
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		i = 0;
		while (line_copy[line_length - 1] != '\n')
		{
			ft_memcpy(line_copy, current_line, line_length);
			line_copy[line_length] = buffer[i];
			line_length++;
			i++;
		}
			free(current_line);
			current_line = malloc(sizeof(char) * (line_length + 1));
			free(line_copy);
			line_copy = malloc(sizeof(char) * (line_length + BUFFER_SIZE));
	}
	current_line[line_length] = '\0';
	free(line_copy);
	return (current_line);
}
