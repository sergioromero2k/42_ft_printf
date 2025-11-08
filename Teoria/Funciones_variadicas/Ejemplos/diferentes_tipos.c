#include <stdarg.h>
#include <stdio.h>

void	mostrar_datos(int cantidad, ...)
{
	va_list	args;
	char	tipo;
	int		i;
	int		val;
	char	val;
	char	*val;

	va_start(args, cantidad);
	i = 0;
	while (i < cantidad)
	{
		tipo = va_arg(args, int);
		if (tipo == 'i')
		{
			val = va_arg(args, int);
			printf("Entero: %d\n", val);
		}
		else if (tipo == 'c')
		{
			val = (char)va_arg(args, int);
			printf("Caracter: %c\n", val);
		}
		else if (tipo == 's')
		{
			val = va_arg(args, char *);
			printf("Cadena: %s\n", val);
		}
		i++;
	}
	va_end(args);
}
int	main(void)
{
	mostrar_datos(3, 'i', 42, 'c', 'A', 's', "Hola mundo");
	return (0);
}
