/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:26:10 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 11:21:55 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_number_upper_letter(int n, int fd)
{
	n %= 16;
	if (n >= 10 && n <= 15)
	{
		n += 55;
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

void	ft_puthex_upper_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return ;
	}
	if (n > 15)
	{
		ft_puthex_fd(n / 16, fd);
		print_number_upper_letter(n, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
