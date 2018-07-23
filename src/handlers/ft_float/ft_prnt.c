#include "ft_printf.h"

void ft_putfloat(ssize_t nbr)
{
	if (nbr >= 10)
	{
		ft_putfloat(nbr / 10);
		ft_putfloat(nbr % 10);
	}
	else
		ft_putchar(nbr % 10 + '0');
}

ssize_t ft_wide(t_tmp *tmp)
{
	ssize_t	count;
	
	count = 1;
	if (tmp->isprs)
	{
		while (tmp->prs > 0)
		{
			count *= 10;
			tmp->prs--;
		}
	}
	else
		count = 1000000;
	return (count);
}
