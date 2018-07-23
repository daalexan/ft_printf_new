#include "ft_printf.h"

static void	ft_putoct(uintmax_t nbr)
{
	if (nbr >= 8)
	{
		ft_putoct(nbr / 8);
		ft_putoct(nbr % 8);
	}
	else
		ft_putchar((nbr % 8) + '0');
}

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{   
    if (tmp->isprs)
        ft_space(len, tmp->prs, '0');
    if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
        ft_putoct(nbr);
} 

static ssize_t ft_length(t_tmp *tmp, ssize_t len)
{
	if (tmp->isprs)
		if (tmp->prs > len)
			len = tmp->prs;
    if (tmp->space || tmp->plus)
        len++;
	if (tmp->hash && len + 1 != tmp->wid && !tmp->zero)
		len++;
    return (len);
}

static ssize_t ft_print(uintmax_t nbr, t_tmp *tmp)
{
	ssize_t nbrstr;
    ssize_t nbrlen;
     
    nbrstr = ft_octlen(nbr);
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
	if (tmp->iswid && !tmp->minus)
        ft_space(nbrlen, tmp->wid, ' ');
	if (tmp->hash)
	{
		ft_putchar('0');
		nbrstr++;
	}
    ft_putsymb(nbr, tmp, nbrstr);
    if (tmp->iswid && tmp->minus)
        ft_space(nbrstr, tmp->wid, ' ');
    return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}

ssize_t	ft_octal_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	uintmax_t	nbr;

	(void)frm;
	(void)i;
	if (frm[*i] == 'O')
		tmp->type = 3;
	nbr = convert(arg, tmp);
	if (tmp->plus && nbr != 0)
	{
		tmp->isprs = 1;
		tmp->prs = FT_MAX(tmp->prs, ft_octlen(nbr) + 1);
	}
	else if (tmp->plus && nbr == 0 && tmp->isprs && tmp->prs == 0)
	{
		if (tmp->iswid && !tmp->minus)
			ft_space(0, tmp->wid, tmp->zero ? '0' : ' ');
		if (tmp->iswid && tmp->minus)
			ft_space(0, tmp->wid, ' ');
		return (tmp->iswid ? FT_MAX(tmp->wid, 1) : 0);
	}
	return (ft_print(nbr, tmp));
}
