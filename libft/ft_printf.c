/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:54:40 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:50:10 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_print_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putlhex(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_putuhex(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *++format)
			count += ft_check_print_format(*format, args);
		else if (*format != '%' && *format)
			count += ft_putchar(*format);
		format++;
	}
	return (va_end(args), count);
}
