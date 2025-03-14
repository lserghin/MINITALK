/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:22:02 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/20 00:55:31 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	char			str[10];
	int				index;
	int				count;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		count = 1;
		nbr *= -1;
	}
	index = 0;
	while (nbr)
	{
		*(str + index++) = (nbr % 10) + '0';
		nbr /= 10;
	}
	count += index;
	while (index)
		write(1, str + --index, 1);
	return (count);
}
