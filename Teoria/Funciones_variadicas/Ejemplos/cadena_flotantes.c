#include <stdarg.h>
#include <stdio.h>

void	print_floats(int count, ...)
{
	va_list	args;
	int		i;
	double	f;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		f = va_arg(args, double);
		printf("Valor #%d = %.2f\n", i + 1, f);
		i++;
	}
	va_end(args);
}
int	main(void)
{
	print_floats(3, 1.5, 2.75, 9.8);
	return (0);
}
