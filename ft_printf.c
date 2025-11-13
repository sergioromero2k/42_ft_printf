/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 11:22:40 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

const char	*handle_specifier(char c, va_list args, int count)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, (char *)), 1);
	}
	else if (c == 'p')
	{
		ft_print_ptr();
	}
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr(va_arg(args, int), 1);
	}
	else if (c == 'u')
	{
		ft_putnbr_unisgned_fd(va_arg(args, int), 1);
	}
	else if (c == 'x')
	{
		ft_puthex_fd(va_arg(args, int), 1);
	}
	else if (c == 'X')
	{
		ft_puthex_fd(va_arg(args, int), 1);
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

	var_arg(args, format);
	count = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i] == '\0')
	{
		if (format[i] == '%')
		{
			handle_specifier(format[i++], args, count);
		}
		else
		{
			write(1, format[i], 1);
		}
	}
	va_end(args);
	return (count);
}
