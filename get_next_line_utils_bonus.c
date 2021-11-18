/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilva <asilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:34:31 by asilva            #+#    #+#             */
/*   Updated: 2021/11/18 10:56:50 by asilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(const void *dst, const void *src, size_t n)
{
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)(dst);
	srcptr = (char *)(src);
	if (dstptr && srcptr)
	{
		while (n--)
			*dstptr++ = *srcptr++;
	}
	return ((void *)dst);
}

//	find first char on a string, and return right side of the string

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (0);
}

// Take a string as input, allocate memory for a copy of it and copy

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;

	if (src)
	{
		len = ft_strlen(src);
		if (!len)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_memcpy(str, src, len);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

//	Return the string length

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*cp;

	i = 0;
	cp = (char *)(s);
	while (cp && *cp)
	{
		cp++;
		i++;
	}
	return (i);
}

//	Take 2 strings as inputs and concatenate them in a new allocated string

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*s;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s)
		return (NULL);
	while (i < (s1len + s2len + 1))
		s[i++] = 0;
	ft_memcpy(s, s1, s1len);
	ft_memcpy(s + s1len, s2, s2len);
	s[s1len + s2len] = '\0';
	return (s);
}
