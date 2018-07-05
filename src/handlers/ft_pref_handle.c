#include "ft_printf.h"

static void ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
    	ft_space(len, tmp->prs, '0');
    if (nbr == 0 && tmp->isprs && tmp->prs == 0)
    	return ;
    else
		ft_putnbr(nbr);
}				 

ssize_t	ft_pref_handle(uintmax_t nbr, char *pref, t_tmp *tmp)
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
	 nbrlen += ft_strlen(pref) + 2;
	 if (tmp->iswid && !tmp->minus)
         ft_space(nbrlen, tmp->wid, ' ');
	 if (pref != NULL)
		 ft_putstr(pref);
	 ft_putsymb(nbr, tmp, nbrstr);
	 if (tmp->iswid && tmp->minus)
		 ft_space(nbrstr, tmp->wid, ' ');
	 return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
