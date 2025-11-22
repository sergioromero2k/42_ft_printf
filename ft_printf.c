/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/22 20:55:37 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	convertidor_parametros(va_list args, char *c, int *count)
{
	if (*c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*c == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (*c == 'd' || *c == 'i')
		ft_putnbr_base(va_arg(args, int), 10, "0123456789", count);
	else if (*c == 'u')
		ft_putnbr_base_unsigned(va_arg(args, unsigned int), 10, "0123456789",
			count);
	else if (*c == 'x')
		ft_putnbr_base_unsigned(va_arg(args, unsigned int), 16,
			"0123456789abcdef", count);
	else if (*c == 'X')
		ft_putnbr_base_unsigned(va_arg(args, unsigned int), 16,
			"0123456789ABCDEF", count);
	else if (*c == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			convertidor_parametros(args, (char *)format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
