#ifndef LIBFTPRINT
# define LIBFTPRINT

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(int n);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base_unisgned(int n);
void	ft_puthex(unsigned int n);
void	ft_puthex_upper(unsigned int n);
#endif
