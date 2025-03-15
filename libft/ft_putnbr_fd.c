/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:27:11 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:50:55 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			*variant_s;
	char			str[10];
	unsigned int	un;

	variant_s = str;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		un = -n;
	}
	else
		un = n;
	while (un)
	{
		*variant_s++ = (un % 10) + '0';
		un /= 10;
	}
	while (variant_s > str)
		write(fd, --variant_s, 1);
	return ;
}
