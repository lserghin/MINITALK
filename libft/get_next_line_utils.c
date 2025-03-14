/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:57:53 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/19 11:52:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_utils(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = ft_strdup((const char *)"");
		if (!s1)
			return (free(s1), NULL);
	}
	if (!s2)
		return (free(s1), NULL);
	s1len = ft_strlen((const char *)s1);
	s2len = ft_strlen((const char *)s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (free(s1), NULL);
	ft_strlcpy(str, (const char *)s1, s1len + 1);
	ft_strlcpy(str + s1len, (const char *)s2, s2len + 1);
	return (free(s1), str);
}
