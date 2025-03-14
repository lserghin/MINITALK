/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:20 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/19 11:34:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*str;
	char	*origin;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	origin = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (origin);
}
