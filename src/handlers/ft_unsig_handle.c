#include "ft_printf.h"

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
