#ifndef LIBFTPRINT
# define LIBFTPRINT

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putnbr_base(long long int n, int base, char *formato, int *count);
void	ft_putnbr_base_unsigned(long long int n, int base, char *formato,
			int *count);
size_t	ft_strlen(const char *s);
int		ft_printf(char const *format, ...);
#endif
