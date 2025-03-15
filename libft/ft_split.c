/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:50:54 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:51:44 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*ft_strdup_len(char *s, size_t len)
{
	char	*str;
	char	*origin;

	origin = malloc(sizeof(char) * (len + 1));
	if (!origin)
		return (NULL);
	str = origin;
	while (len--)
		*str++ = *s++;
	*str = '\0';
	return (origin);
}

static void	ft_free_mem(char **strings, char **variant_s)
{
	while (--variant_s >= strings)
		free(*variant_s);
	free(strings);
}

static char	*ft_skip_sep(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	**variant_s;
	char	*start;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!strings)
		return (NULL);
	variant_s = strings;
	while (*s)
	{
		s = ft_skip_sep(s, c);
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			*variant_s = ft_strdup_len(start, s - start);
			if (!*variant_s)
				return (ft_free_mem(strings, variant_s), NULL);
			variant_s++;
		}
	}
	return (*variant_s = NULL, strings);
}
