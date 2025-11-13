/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unisgned_fd .c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:56 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/13 10:15:49 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unisgned_fd(int n, int fd)
{
	if (n > 9)
		ft_putnbr_unisgned_fd(n / 10, fd);
	ft_putstr_fd(n % 10 + '0', fd);
}
