#include "ft_printf.h"

ssize_t ft_nbrlen(ssize_t n)
{
	ssize_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void ft_putn(uintmax_t n, size_t len)
{
	int i;
	char *str;

    i = 0;
    if (!(str = (char*)malloc(sizeof(char) *
					(ft_nbrlen(n) + 1))))
		return ;
    while (n > 0)
    {
		str[i] = n % 10 + '0';
    	n /= 10;
        i++;
    }
    str[i] = '\0';
    i--;
    while (len-- != 0)
		ft_putchar(str[i--]);
    free(str);
}
