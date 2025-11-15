/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:36:42 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/15 18:02:56 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char s, size_t *counter)
{
	write(1, &s, 1);
	++(*counter);
}
void	ft_putstr(char *s, size_t *counter)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar_fd(*s, counter);
		s++;
	}
}
void	ft_putptr(void *ptr, int *count)
{
	unsigned long	num;

	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	num = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_putnbr_base(num, 16, "0123456789abcdef", count);
}
void	ft_putnbr_base(long long int n, int base, char *formato, int *count)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', count);
	}
	if (n >= base)
		ft_putnbr_base(n / base, base, formato, count);
	ft_putchar(formato[n % base], count);
}
void	ft_putnbr_base_unsigned(long long int n, int base, char *formato,
		int *count)
{
	if (n >= base)
		ft_putnbr_base_unsigned(n / base, base, formato, count);
	ft_putchar(formato[n % base], count);
}
