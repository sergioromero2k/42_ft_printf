/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/14 17:49:41 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

void	convertidor_parametros(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), 10, "0123456789", count);
	else if (c == 'u')
		ft_putnbr_base_unsigned(va_arg(args, unsigned int), 10, "0123456789",
			count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, int), 16, "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, int), 16, "0123456789ABCDEF", count);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] && !ft_is_conversion(format[i]))
				i++; // IGNORA flags/ancho/lo que sea
			if (format[i])
				convertidor_parametros(format[i], args, &count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
