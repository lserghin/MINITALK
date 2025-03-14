/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:30:05 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/19 11:21:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	diff;

	srclen = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (srclen);
	dstlen = ft_strlen((const char *)dst);
	diff = dstsize - dstlen - 1;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	while (*src && diff--)
		*(dst++ + dstlen) = *src++;
	*(dst + dstlen) = '\0';
	return (dstlen + srclen);
}
