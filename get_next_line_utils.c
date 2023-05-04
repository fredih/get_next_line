/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:18:16 by aantonio          #+#    #+#             */
/*   Updated: 2023/05/04 16:16:57 by aantonio         ###   ########.fr       */
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

int	find_char(const char *s, int c)
{
	size_t	i;

	i = 1;
	while (i <= ft_strlen(s))
	{
		if ((unsigned char)s[i - 1] == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}

// int	find_char(const char *s, int c, size_t len)
// {
// 	size_t	i;

// 	i = 1;
// 	while (i <= len)
// 	{
// 		if ((unsigned char)s[i - 1] == (unsigned char)c)
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

int	find_2nd_char(const char *s, int c, size_t len)
{
	size_t	i;
	size_t	counter;
	size_t	first_index;

	i = 1;
	counter = 0;
	while (i < len)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			counter++;
			if (counter == 1)
				first_index = i;
			if (counter == 2)
				return (i - first_index);
		}
		i++;
	}
	return (i - first_index);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char				*charptr;
	unsigned int		i;

	charptr = (char *)s;
	i = 0;
	while (i < n)
	{
		*(charptr + i) = (unsigned char)c;
		i++;
	}
	return (charptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}


size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1len;
	size_t	s2len;
	int		i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!newstr)
		return (0);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[s1len + i] = s2[i];
		i++;
	}
	newstr[s1len + i] = '\0';
	return (newstr);
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*newstr;
	
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s, len + 1);
	return (newstr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	src_length;

	src_length = 0;
	while (src[src_length])
	{
		src_length++;
	}
	if (!dest || n == 0)
		return (src_length);
	i = 0;
	while (i < (n - 1) && i < src_length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_length);
}
