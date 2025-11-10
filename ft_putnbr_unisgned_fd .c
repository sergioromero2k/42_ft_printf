/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unisgned_fd .c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:56 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/10 12:23:07 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unisgned_fd (int n, int fd)
{
	if (n > 9)
		ft_putnbr_unisgned_fd (n / 10, fd);
	ft_putstr_fd(n % 10 + '0', fd);
}
