/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:04:52 by serromer          #+#    #+#             */
/*   Updated: 2025/11/13 22:41:20 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(void *ptr)
{
	unsigned long num;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return ;
	}
	num = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putnbr_base(num, 16, "0123456789abcdef");
}