/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:57:23 by aantonio          #+#    #+#             */
/*   Updated: 2023/04/27 22:11:02 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(void)
{
	int		my_file;
	char	*current_line;
	
	printf("READING\n");
	my_file = open("my_file.txt", O_RDONLY);
	current_line = get_next_line(my_file);
	printf("BEFORE\n");
	printf("%s", current_line);
	printf("AFTER\n");
	current_line = get_next_line(my_file);
	printf("%s", current_line);
	printf("AFTER 2\n");
	current_line = get_next_line(my_file);
	printf("%s", current_line);
	printf("AFTER 3\n");
	return (0);
}
