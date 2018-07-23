#include "ft_printf.h"

static ssize_t ft_binlen(uintmax_t nbr)
{
	ssize_t i;
	
	i = 0;
	while (nbr != 0)
	{
		nbr /= 2;
		i++;
	}
	return (i);
}

void	ft_putbin(uintmax_t nbr)
{
	if (nbr >= 2)
	{
		ft_putbin(nbr / 2);
		ft_putbin(nbr % 2);
	}
	else
		ft_putchar((nbr % 2) + '0');
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

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
		ft_space(len, tmp->prs, '0');
	if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
        ft_putbin(nbr);
}

ssize_t	ft_binary_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	ssize_t		nbrstr;
	ssize_t		nbrlen;
	intmax_t	nbr;
	
	(void)frm;
	(void)i;
	nbr = va_arg(*arg, intmax_t);
	nbrstr = ft_binlen(nbr);
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


