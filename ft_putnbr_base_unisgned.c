/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unisgned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:56 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 22:24:38 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base_unisgned(long long int n, int base, char *formato)
{
	if (n >= base)
		ft_putnbr_base_unisgned(n / base, base, formato);
	ft_putstr(formato[n % base]);
}
