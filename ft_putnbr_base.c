/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:56 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 22:24:14 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
