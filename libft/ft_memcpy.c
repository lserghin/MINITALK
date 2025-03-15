/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:23:42 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:49:41 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*variant_d;
	unsigned char		*variant_s;

	if (!dest && !src)
		return (NULL);
	variant_d = (unsigned char *)dest;
	variant_s = (unsigned char *)src;
	while (n--)
		*variant_d++ = *variant_s++;
	return (dest);
}
