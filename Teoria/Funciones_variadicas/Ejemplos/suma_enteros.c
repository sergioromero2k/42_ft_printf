#include <stdarg.h>
#include <stdio.h>

int	suma(int cantidad, ...)
{
	va_list	args;
	int		total;
	int		i;
	int		num;

	va_start(args, cantidad);
	total = 0;
	i = 0;
	while (i < cantidad)
	{
		num = va_arg(args, int);
		total += num;
		i++;
	}
	va_end(args);
	return (total);
}
int	main(void)
{
	printf("Suma %d\n", suma(4, 10, 20, 30, 40)); // 100
	return (0);
}