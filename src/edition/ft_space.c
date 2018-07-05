#include "ft_printf.h"

void	ft_space(ssize_t len, int width, char symb)
{
	ssize_t line;
	
	line = (ssize_t)(width - len);
	while (line > 0)
	{
		ft_putchar(symb);
		line--;
	}
}

