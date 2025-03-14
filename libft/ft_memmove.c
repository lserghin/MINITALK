/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:55 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/19 11:20:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*variant_d;
	unsigned char		*variant_s;

	if (!dest && !src)
		return (NULL);
	variant_d = (unsigned char *)dest;
	variant_s = (unsigned char *)src;
	if (variant_d > variant_s)
	{
		variant_d = (unsigned char *)dest + n - 1;
		variant_s = (unsigned char *)src + n - 1;
		while (n--)
			*variant_d-- = *variant_s--;
		return (dest);
	}
	else
	{
		while (n--)
			*variant_d++ = *variant_s++;
		return (dest);
	}
}
