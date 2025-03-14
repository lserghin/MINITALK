/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:20:49 by lserghin          #+#    #+#             */
/*   Updated: 2025/01/20 00:55:42 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6), 6);
	count = 0;
	while (*(str + count))
		write(1, str + count++, 1);
	return (count);
}
