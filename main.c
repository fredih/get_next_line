/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:57:23 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/05 14:19:48 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int		my_file;
	char	*current_line;

	// printf("READING\n");


	//test if multiple_line_no_nl is good line by line
	// my_file = open("multiple_line_no_nl", O_RDONLY);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "01234567890123456789012345678901234567890\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "987654321098765432109876543210987654321098\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789012\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "987654321098765432109876543210987654321098\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "01234567890123456789012345678901234567890"));


	//test if variable_nls.txt is good line by line
	// my_file = open("variable_nls.txt", O_RDONLY);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789x2\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789x3\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789x5\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789x8\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "\n"));
	// free(current_line);
	// printf("%d", strcmp((current_line = get_next_line(my_file)), "0123456789012345678901234567890123456789x12"));
	// free(current_line);
	// printf("%p", NULL);

	// my_file = 6;
	my_file = open("mf.txt", O_RDONLY);
	// my_file = open("multiple_line_no_nl", O_RDONLY);
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
	close(my_file);
	return (0);
}
