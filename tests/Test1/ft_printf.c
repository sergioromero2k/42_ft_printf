/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 06:33:27 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/15 07:15:50 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *s, size_t *counter)
{
	if (*s == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*s == 's')
		ft_format;
	else if (*s == 'p')
		ft_format;
	else if (*s == 'd' || *s = 'i')
		ft_printf;
	else if (*s == 'u')
		ft_format;
	else if (*s == 'x')
		ft_format();
	else if (*s == 'X')
		ft_format();
	else if (*s == '%')
		ft_format;
}

int	ft_printf(char const *string, ...)
{
	va_list	va;
	size_t	counter;

	if (!string)
		return (-1);
	va_start(va, string);
	counter = 0;
	while (*str)
	{
		if (string == '%')
		{
			string++;
			ft_format(va, (char *)string, &counter);
		}
		else
			ft_putchar(*string, &counter);
		string++;
	}
	va_end(va);
	return (counter);
}
