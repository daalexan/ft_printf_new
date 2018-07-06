#include "ft_printf.h"

static intmax_t	convert_type(va_list *arg, t_tmp *tmp)
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

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
		ft_space(len, tmp->prs, '0');
	if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
        ft_putnbr(nbr);
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
    nbrlen = FT_MAX(tmp->prs, tmp->wid) - FT_MAX(tmp->prs, nbrstr);
	if (tmp->iswid && !tmp->minus)
        ft_space(nbrlen, tmp->wid, ' ');
    ft_putsymb(nbr, tmp, nbrstr);
    if (tmp->iswid && tmp->minus)
        ft_space(nbrstr, tmp->wid, ' ');
    return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}

ssize_t	ft_int_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	intmax_t	nbr;
	char		*pref;

	(void)i;
	(void)frm;
	nbr = convert_type(arg, tmp);
	if (tmp->isprs)
		tmp->zero = 0;
	if (nbr < 0 || tmp->space || tmp->plus)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			pref = "-";
		}
		else if (tmp->plus)
			pref = "+";
		else if (tmp->space)
			pref = " ";
		else
			pref = "";
		return (ft_pref_handle(nbr, pref, tmp));
	}
	else
		return (ft_print_int(nbr, tmp));
}
