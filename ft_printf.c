/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:24:57 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/09 10:37:23 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

const char	*handle_specifier(char c, va_list args, int count)
{
	if (c == 's')
	{
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 's')
	{
		ft_putstr_fd(va_arg(args, (char *)), 1);
	}else if(c=='p'){
		ft_print_ptr(

	int ft_printf(char const *format, ...)
	{
		va_list args;

		var_arg(args, x);
		int count;

		count = 0;
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
	}
