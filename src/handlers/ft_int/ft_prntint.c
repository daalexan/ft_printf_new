#include "ft_printf.h"

intmax_t	convert_type(va_list *arg, t_tmp *tmp)
{
	intmax_t	nbr;

	nbr = va_arg(*arg, intmax_t);
	if (tmp->type == 1)
		nbr = (char)nbr;
	else if (tmp->type == 2)
		nbr = (short int)nbr;
	else if (tmp->type == 3)
		nbr = (long int)nbr;
	else if (tmp->type == 4)
		nbr = (long long int)nbr;
	else if (tmp->type == 5)
		nbr = (intmax_t)nbr;
	else if (tmp->type == 6)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

void	ft_putint(uintmax_t nbr)
{
	if (nbr >= 10)
	{
		ft_putint(nbr / 10);
		ft_putint(nbr % 10);
	}
	else
		ft_putchar((nbr % 10) + '0');
}

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
		ft_space(len, tmp->prs, '0');
	if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
        ft_putint(nbr);
}

static ssize_t ft_length(t_tmp *tmp, ssize_t len)
{
	if (tmp->isprs)
		if (tmp->prs > len)
			len = tmp->prs;
	if (tmp->space || tmp->plus)
		len++;
	return (len);
}

ssize_t ft_print_int(uintmax_t nbr, t_tmp *tmp)
{
    ssize_t nbrstr;
	ssize_t nbrlen;

	nbrstr = ft_nbrlen(nbr);
	if (tmp->iswid && !tmp->minus && tmp->zero)
	{
		if (tmp->isprs)
        	tmp->prs = FT_MAX(tmp->wid, tmp->prs);
        else
        	tmp->prs = FT_MAX(tmp->wid, nbrstr);
        tmp->iswid = 0;
        tmp->isprs = 1;
    }
    nbrlen = ft_length(tmp, nbrstr);
	if (tmp->iswid && !tmp->minus && tmp->wid > tmp->prs)
		ft_space(nbrlen, tmp->wid, ' ');
	ft_putsymb(nbr, tmp, nbrstr);
	if (tmp->iswid && tmp->minus)
        ft_space(nbrlen, tmp->wid, ' ');
    return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
