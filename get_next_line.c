/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/03 15:20:52 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*line_copy;
	size_t		line_length;
	size_t		char_index;
	static char	*buffer = NULL;

	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	line_length = BUFFER_SIZE;
	current_line = malloc(sizeof(char) * (line_length + 1));
	if (read(fd, current_line, BUFFER_SIZE) == 0)
	{
		free(current_line);
		return (NULL);
	}
	line_copy = malloc(sizeof(char) * (line_length + 1));
	while (current_line[line_length - 1] != '\n')
	{
		ft_memcpy(line_copy, current_line, line_length);
		if (read(fd, &line_copy[line_length], BUFFER_SIZE) != BUFFER_SIZE)
			break ;
		char_index = find_char(line_copy, '\n', line_length + BUFFER_SIZE);
		if (char_index > 0)
		{
			ft_memcpy(current_line, line_copy, line_length + char_index);
			if (BUFFER_SIZE > 1)
				ft_memcpy(buffer, &line_copy[char_index],
					(line_length + BUFFER_SIZE) - char_index + 1);
			line_length = char_index + 1;
			break ;
		}
		free(current_line);
		current_line = malloc(sizeof(char) * (line_length + BUFFER_SIZE + 1));
		ft_memcpy(current_line, line_copy, line_length + BUFFER_SIZE + 1);
		line_length += BUFFER_SIZE;
		free(line_copy);
		line_copy = malloc(sizeof(char) * (line_length + BUFFER_SIZE));
	}
	current_line[line_length] = '\0';
	free(line_copy);
	return (current_line);
}
