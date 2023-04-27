/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/04/27 22:38:23 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*line_copy;
	size_t		line_length;

	line_length = 1;
	current_line = malloc(sizeof(char) * line_length);
	if (read(fd, current_line, 1) != 1)
	{
		free(current_line);
		return (NULL);
	}
	line_copy = malloc(sizeof(char) * (line_length + 1));
	while (current_line[line_length - 1] != '\n')
	{
		ft_memcpy(line_copy, current_line, line_length);
		if (read(fd, &line_copy[line_length], 1) != 1)
			break ;
		free(current_line);
		current_line = malloc(sizeof(char) * (line_length + 1));
		ft_memcpy(current_line, line_copy, line_length + 1);
		line_length++;
		free(line_copy);
		line_copy = malloc(sizeof(char) * (line_length + 1));
	}
	free(line_copy);
	return (current_line);
}
