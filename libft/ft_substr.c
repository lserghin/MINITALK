/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:50:17 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/19 11:22:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup_len("", 0));
	if (start + len > slen)
		len = slen - start;
	str = ft_strdup_len((char *)(s + start), len);
	return (str);
}
