/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 22:20:49 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

const char	*convertidor_parametros(char c, va_list args, int count)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
	}
	else if (c == 's')
	{
		ft_putstr(va_arg(args, (char *)));
	}
	else if (c == 'p')
	{
		ft_putptr();
	}
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr(va_arg(args, int), 10, "0123456789");
	}
	else if (c == 'u')
	{
		ft_putnbr_unisgned_fd(va_arg(args, int), 1);
	}
	else if (c == 'x')
	{
		ft_putnbr(va_arg(args, int), 16, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		ft_putnbr(va_arg(args, int), 16, "0123456789ABCDEF");
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
	}
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
	while (format[i] == '\0')
	{
		if (format[i] == '%')
		{
			convertidor_parametros(format[i++], args, count);
		}
		else
		{
			ft_putchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}
