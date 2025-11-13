/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:16:30 by serromer          #+#    #+#             */
/*   Updated: 2025/11/13 11:21:04 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_number_letter(int n, int fd)
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

void	ft_puthex_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return ;
	}
	if (n > 15)
	{
		ft_puthex_fd(n / 16, fd);
		print_number_letter(n, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}

int	main(void)
{
	int number = 1515115;

	printf("A: %X\n", number);
	printf("\n");
	ft_puthex_fd(number, 1);

	// printf("Hola mundo cruel %x\n", number);
	// printf("Hola mundo cruel %x\n", number);
	// printf("Hola mundo cruel %x\n", number);
}