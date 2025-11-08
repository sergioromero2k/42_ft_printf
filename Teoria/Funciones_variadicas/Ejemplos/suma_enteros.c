#include <stdarg.h>
#include <stdio.h>

int	suma(int cantidad, ...)
{
	va_list	args;
	int		total;
	int		num;

	va_start(args, cantidad);
	total = 0;
	for (int i = 0; i < cantidad; i++)
	{
		num = va_arg(args, int);
		printf("%d\n", num);
		total += num;
	}
	va_end(args);
	return (total);
}
int	main(void)
{
	printf("Suma: %d\n", suma(4, 19, 20, 30, 40));
}