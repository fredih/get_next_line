/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:09:13 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/03 14:05:10 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*line_copy;
	size_t		line_length;

	line_length = 1;
	current_line = malloc(sizeof(char) * (line_length + 1));
	if (read(fd, current_line, 1) != 1)
	{
		free(current_line);
		return (NULL);
	}
	line_copy = malloc(sizeof(char) * (line_length + 1));
	while (current_line[line_length - 1] != '\n')
	{
		if (line_length == 23)
		{
			int j = 1;
			j++;
		}
		ft_memcpy(line_copy, current_line, line_length);
		if (read(fd, &line_copy[line_length], 1) != 1)
			break ;
		free(current_line);
		current_line = malloc(sizeof(char) * (line_length + 2));
		ft_memcpy(current_line, line_copy, line_length + 1);
		line_length++;
		free(line_copy);
		line_copy = malloc(sizeof(char) * (line_length + 1));
	}
	current_line[line_length] = '\0';
	free(line_copy);
	return (current_line);
}
