/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:06:05 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/20 00:55:55 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int unbr)
{
	char			str[10];
	int				index;
	int				count;

	if (unbr == 0)
		return (write(1, "0", 1), 1);
	index = 0;
	while (unbr)
	{
		*(str + index++) = (unbr % 10) + '0';
		unbr /= 10;
	}
	count = index;
	while (index)
		write(1, str + --index, 1);
	return (count);
}
