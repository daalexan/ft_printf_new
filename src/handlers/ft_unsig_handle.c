#include "ft_printf.h"

static uintmax_t convert(va_list *arg, t_tmp *tmp)
{
	uintmax_t	nbr;

	nbr = va_arg(*arg, uintmax_t);
	if (tmp->type == 1)
		nbr = (unsigned char)nbr;
	else if (tmp->type == 2)
		nbr = (unsigned short int)nbr;
	else if (tmp->type == 3)
		nbr = (unsigned long int)nbr;
	else if (tmp->type == 4)
		nbr = (unsigned long long int)nbr;
	else if (tmp->type == 5)
		nbr = (uintmax_t)nbr;
	else if (tmp->type == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

static void ft_putunsig(uintmax_t nbr)
{
	char *num = "0123456789";
	if (nbr >= 10)
	{
		ft_putunsig(nbr / 10);
		ft_putunsig(nbr % 10);
	}
	else
		ft_putchar(num[nbr]);
}

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
    if (tmp->isprs)
        ft_space(len, tmp->prs, '0');
    if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
        ft_putunsig(nbr);
}				 

ssize_t ft_unsig_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	uintmax_t	nbr;
	ssize_t		nbrlen;
	ssize_t		nbrstr;

	(void)frm;
	(void)i;
	nbr = convert(arg, tmp);
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
    nbrlen = FT_MAX(tmp->prs, tmp->wid) - FT_MAX(tmp->prs, nbrstr);
    if (tmp->iswid && !tmp->minus)
        ft_space(nbrlen, tmp->wid, ' ');
    ft_putsymb(nbr, tmp, nbrstr);
    if (tmp->iswid && tmp->minus)
        ft_space(nbrstr, tmp->wid, ' ');
    return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
