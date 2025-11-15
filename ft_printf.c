/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/15 18:05:15 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convertidor_parametros(va_list args, char *c, int *count)
{
	if (*c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*c == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (*c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), 10, "0123456789", count);
	else if (*c == 'u')
		ft_putnbr_base_unsigned(va_arg(args, unsigned int), 10, "0123456789",
			count);
	else if (*c == 'x')
		ft_putnbr_base((long long int)va_arg(args, int), 16, "0123456789abcdef",
			count);
	else if (*c == 'X')
		ft_putnbr_base((long long int)va_arg(args, int), 16, "0123456789ABCDEF",
			count);
	else if (*c == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			convertidor_parametros(args, *format, &count);
		}
		else
			ft_putchar(*str, &counter) str++;
	}
	va_end(args);
	return (count);
}
