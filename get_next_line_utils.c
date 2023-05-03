/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:18:16 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/03 14:50:02 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*chardest;
	char		*charsrc;

	if (n > 0 && !src && !dest)
		return (dest);
	chardest = (char *)dest;
	charsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		*(chardest + i) = *(charsrc + i);
		i++;
	}
	return (dest);
}

int	find_char(const char *s, int c, size_t len)
{
	size_t	i;

	i = 1;
	while (i < len)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}

