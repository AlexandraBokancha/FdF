/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:04:22 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:51:23 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, va_list argc, int len_return)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				len_return += ft_putchar(va_arg(argc, int));
			else if (*format == 's')
				len_return += ft_putstr(va_arg(argc, char *));
			else if (*format == 'p')
				len_return += ft_find_adress(va_arg(argc, void *));
			else if (*format == 'd' || *format == 'i')
				len_return += ft_putnbr(va_arg(argc, int));
			else if (*format == 'u')
				len_return += ft_putnbr_unsgnd(va_arg(argc, unsigned int));
			else if (*format == 'x' || *format == 'X')
				len_return += ft_hex(va_arg(argc, unsigned int), *format);
			else if (*format == '%')
				len_return += ft_putchar('%');
		}
		else
			len_return += ft_putchar(*format);
		format++;
	}
	return (len_return);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len_return;

	len_return = 0;
	va_start(args, format);
	len_return = check_format(format, args, len_return);
	va_end(args);
	return (len_return);
}
