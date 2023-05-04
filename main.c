/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:57:23 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/04 19:25:43 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(void)
{
	int		my_file;
	char	*current_line;

	printf("READING\n");
	my_file = open("asd", O_RDONLY);
	while((current_line = get_next_line(my_file)))
	{
		printf("%s", current_line);
		free(current_line);
	}
	free(current_line);
	// current_line = get_next_line(my_file);
	// printf("BEFORE\n");
	// printf("%s", current_line);
	// printf("AFTER\n");
	// current_line = get_next_line(my_file);
	// printf("%s", current_line);
	// printf("AFTER 2\n");
	// current_line = get_next_line(my_file);
	// printf("%s", current_line);
	// printf("AFTER 3\n");
	return (0);
}
