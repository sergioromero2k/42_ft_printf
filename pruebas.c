/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:16:30 by serromer          #+#    #+#             */
/*   Updated: 2025/11/13 22:42:30 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr_base(long long int n, int base, char *formato)
{
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= base)
		ft_putnbr_base(n / base, base, formato);
	ft_putchar(formato[n % base]);
}

void	ft_putptr(void *ptr)
{
	unsigned long	num;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return ;
	}
	num = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putnbr_base(num, 16, "0123456789abcdef");
}

int	main(void)
{
	int	*number;
	int	i;

	i = 5;
	number = &i;
	printf("A: %p\n", &i);
	ft_putptr(number);
	// printf("Hola mundo cruel %x\n", number);
	// printf("Hola mundo cruel %x\n", number);
	// printf("Hola mundo cruel %x\n", number);
}
