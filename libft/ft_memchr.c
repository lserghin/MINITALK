/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:18:16 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:49:33 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*variant_s;

	variant_s = (unsigned char *)s;
	while (n--)
	{
		if (*variant_s == (unsigned char)c)
			return ((void *)variant_s);
		variant_s++;
	}
	return (NULL);
}
