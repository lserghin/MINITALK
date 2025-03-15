/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:47:16 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:52:19 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	char	*variant_s;

	if (!str)
		return (0);
	variant_s = (char *)str;
	while (*variant_s)
		variant_s++;
	return ((size_t)(variant_s - str));
}
