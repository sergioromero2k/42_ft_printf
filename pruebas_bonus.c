/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:41:41 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/11/16 10:36:11 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	// FLAG - (alineación a la izquierda)
	printf("|%-10d|\n", 42);
	// FLAG - (alineación a la derecha)
	printf("|%10d-|\n", 42);
	// FLAG 0 (relleno con ceros), no puedo hacer por la derecha
	printf("|%010d|\n", 42);
	// ANCHO MÍNIMO (field minimum width)
	printf("|%7s|\n", "hey");
	// PRECISIÓN (.num).
	// Para enteros → mínimo de dígitos
	printf("|%.5d|\n", 42);
	printf("|%.10d|\n", 42);
	printf("|%-.15d|\n", 42);
	// Para cadenas → máximo de caracteres
	printf("|%.5s|\n", "holap");
	printf("|%.3s|\n", "holap");
	printf("|%-.15s|\n", "holap");
	// Combinaciones comunes
	printf("|%-10.3s\n", "Hola");
	printf("|% d|\n", 42);
	printf("|% d|\n", -42);
}
