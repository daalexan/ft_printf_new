#include "ft_printf.h"

static void ft_print(size_t exp, char *znk)
{
	ft_putchar(znk[0]);
	ft_putchar(znk[1]);
	if (exp < 10)
	{
		ft_putchar('0');
		ft_putfloat(exp);
	}
	else
		ft_putfloat(exp);
}

static ssize_t ft_sciprnt(double nbr, size_t exp, t_tmp *tmp, char *znk)
{
	ssize_t	start;
	ssize_t	end;
	size_t	len;
	
	len = 0;
	start = nbr;
	len += ft_nbrlen(start) + 1;
	ft_putfloat(start);
	ft_putchar('.');
	nbr -= start;
	end = nbr * ft_wide(tmp) + 0.5;
	len += ft_nbrlen(end);
	ft_putfloat(end);
	ft_print(exp, znk);
	return (len + 4);
}

static void ft_mkexp(size_t *exp, double *nbr, char *znk)
{
	size_t start;
	
	start = *nbr;
	if (start == 0)
	{
		znk[1] = '-';
		while (*nbr < 1)
		{
			(*nbr) *= 10;
			(*exp)++;
		}
	}
	else
	{
		znk[1] = '+'; 
		while (start > 10)
		{
			(*nbr) /= 10;
			(*exp)++;
			start = *nbr;
		}
	}
}

static void ft_pref(t_tmp *tmp, ssize_t *len, double *nbr)
{
	if (tmp->plus || tmp->space)
	{
		if (tmp->plus)
			ft_putchar('+');
		else if (tmp->space)
			ft_putchar(' ');
		(*len)++;
	}
	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		ft_putchar('-');
		(*len)++;
	}
}

ssize_t ft_scinot_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	ssize_t len;
	double	nbr;
	size_t	exp;
	char	znk[2];
	
	znk[0] = 'e';
	exp = 0;
	len = 0;
	if (frm[*i] == 'E')
		znk[0] = 'E';
	nbr = va_arg(*arg, double);
	ft_pref(tmp, &len, &nbr);
	ft_mkexp(&exp, &nbr, znk);
	return (len + ft_sciprnt(nbr, exp, tmp, znk));
}
