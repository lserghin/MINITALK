/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:06:02 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:52:40 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_starttrim(const char *s1, const char *set)
{
	char	*origin;

	while (*s1)
	{
		origin = (char *)set;
		while (*s1 != *set && *set)
			set++;
		if (*set == '\0')
			return ((char *)s1);
		else
		{
			s1++;
			set = origin;
		}
	}
	return ((char *)s1);
}

static char	*ft_endtrim(const char *s1, const char *set, size_t len)
{
	char	*origin;

	while (len)
	{
		origin = (char *)set;
		while (*s1 != *set && *set)
			set++;
		if (*set == '\0')
			return ((char *)s1);
		else
		{
			s1--;
			len--;
			set = origin;
		}
	}
	return ((char *)s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	char	*s1_start;
	char	*s1_end;
	char	*origin;

	if (!s1)
		return (NULL);
	s1_start = ft_starttrim(s1, set);
	s1_end = ft_endtrim(s1 + ft_strlen(s1) - 1, set, ft_strlen(s1));
	if (s1_start > s1_end)
		return (ft_strdup(""));
	strtrim = malloc(sizeof(char) * (s1_end - s1_start) + 2);
	if (!strtrim)
		return (NULL);
	origin = strtrim;
	while (*s1_start && s1_start <= s1_end)
		*strtrim++ = *s1_start++;
	*strtrim = '\0';
	return (origin);
}
