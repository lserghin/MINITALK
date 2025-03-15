/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:39:45 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:51:35 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuhex(unsigned int nbr)
{
	char			*base;
	int				str[20];
	int				index;
	int				count;

	base = "0123456789ABCDEF";
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	index = 0;
	while (nbr)
	{
		*(str + index++) = nbr % 16;
		nbr /= 16;
	}
	count = index;
	while (index)
		write(1, base + (*(str + --index)), 1);
	return (count);
}
