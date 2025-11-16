/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:16:30 by serromer          #+#    #+#             */
/*   Updated: 2025/11/15 19:41:32 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int		num;
	char	c;
	char	*str;

	num = 42;
	c = 'A';
	str = "Hola Mundo";
	ft_printf("Función ft_printf:\n");
	ft_printf("Caracter: %c\n", c);
	ft_printf("Número: %d\n", num);
	ft_printf("String: %s\n", str);
	ft_printf("Hex: %x\n", num);
	ft_printf("Puntero: %p\n", str);
	ft_printf("Devuelve: %d\n", ft_printf("%d\n", num));
	//
	ft_printf("\n\nFunción printf:\n");
	printf("Caracter: %c\n", c);
	printf("Número: %d\n", num);
	printf("String: %s\n", str);
	printf("Hex: %x\n", num);
	printf("Puntero: %p\n", str);
	printf("Porcentaje: %%\n");
	return (0);
}

// ➜ 42_ft_printf git : (main) ✗ cc pruebas.c libftprintf.a - o pruebas
