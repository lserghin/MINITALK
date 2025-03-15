/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:39:28 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:52:35 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;
	char	*variant_s;

	find = NULL;
	variant_s = (char *)s;
	while (*variant_s)
	{
		if (*variant_s == (char)c)
			find = variant_s;
		variant_s++;
	}
	if (*variant_s == (char)c)
		return (variant_s);
	return (find);
}
