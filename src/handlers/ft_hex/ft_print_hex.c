#include "ft_printf.h"

static void	ft_puthex(uintmax_t nbr, char c)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, c);
	if (nbr % 16 < 10)
		ft_putchar((nbr % 16) + '0');
	else
		ft_putchar((nbr % 16) - 10 + c);
}

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp,\
		unsigned len, char *hex)
{
    if (tmp->isprs)
        ft_space(len, tmp->prs, '0');
    if (nbr == 0 && tmp->isprs && tmp->prs == 0)
        return ;
    else
	{
		if (hex[1] == 'X')
    		ft_puthex(nbr, 'A');
		else if (hex[1] == 'x')
			ft_puthex(nbr, 'a');
	}
}

static ssize_t ft_hexlen(intmax_t nbr)
{
	ssize_t len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static void	ft_peref(ssize_t nbr, t_tmp *tmp)
{
	if (tmp->iswid && !tmp->minus && tmp->zero)
    {
        if (tmp->isprs)
            tmp->prs = FT_MAX(tmp->wid, tmp->prs);
        else
        {   
            tmp->prs = FT_MAX(tmp->wid, nbr);
            if (tmp->hash)
                tmp->prs -= 2;
        }
        tmp->iswid = 0;
        tmp->isprs = 1;
    }
}

ssize_t	ft_print_hex(intmax_t nbr, t_tmp *tmp, char *hex)
{
	ssize_t nbrstr;
    ssize_t nbrlen;

    nbrstr = ft_hexlen(nbr);
	ft_peref(nbrstr, tmp);
    nbrlen = FT_MAX(tmp->prs, tmp->wid) - FT_MAX(tmp->prs, nbrstr);
	if (tmp->hash)
		nbrlen += 2;
	if (tmp->iswid && !tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	if (tmp->hash)
		ft_putstr(hex);
    ft_putsymb(nbr, tmp, nbrstr, hex);
    if (tmp->iswid && tmp->minus)
        ft_space(nbrstr, tmp->wid, ' ');
    return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);		
}
