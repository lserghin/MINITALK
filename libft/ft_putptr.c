/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:04:09 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/20 00:55:36 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	char			*base;
	unsigned long	unb;
	int				str[20];
	int				index;
	int				count;

	base = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5), 5);
	unb = (unsigned long)ptr;
	index = 0;
	while (unb)
	{
		*(str + index++) = unb % 16;
		unb /= 16;
	}
	count = index;
	count += write (1, "0x", 2);
	while (index)
		write(1, base + (*(str + --index)), 1);
	return (count);
}
