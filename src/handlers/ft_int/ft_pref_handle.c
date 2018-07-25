/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pref_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:08:12 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/24 19:08:13 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnum(uintmax_t nbr)
{
	if (nbr > 9)
	{
		ft_putnum(nbr / 10);
		ft_putnum(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

static void		ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
		ft_space(len, tmp->prs, '0');
	if (nbr == 0 && tmp->isprs && tmp->prs == 0)
		return ;
	else
		ft_putnum(nbr);
}

static ssize_t	ft_length(t_tmp *tmp, ssize_t len, char *pref)
{
	if (tmp->isprs)
		if (tmp->prs > len)
			len = tmp->prs;
	if (*pref == '-')
	{
		tmp->plus = 0;
		tmp->space = 0;
		len++;
	}
	if (tmp->space || tmp->plus)
		len++;
	return (len);
}

static ssize_t	ft_nbr(uintmax_t nbr)
{
	ssize_t len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

ssize_t			ft_pref_handle(uintmax_t nbr, char *pref, t_tmp *tmp)
{
	ssize_t nbrstr;
	ssize_t nbrlen;

	nbrstr = ft_nbr(nbr);
	if (tmp->iswid && !tmp->minus && tmp->zero)
	{
		if (tmp->isprs)
			tmp->prs = FT_MAX(tmp->wid, tmp->prs);
		else
			tmp->prs = FT_MAX(tmp->wid, nbrstr);
		tmp->prs--;
		tmp->iswid = 0;
		tmp->isprs = 1;
	}
	nbrlen = ft_length(tmp, nbrstr, pref);
	if (tmp->iswid && !tmp->minus && tmp->wid > tmp->prs)
		ft_space(nbrlen, tmp->wid, ' ');
	if (pref != NULL)
		ft_putstr(pref);
	ft_putsymb(nbr, tmp, nbrstr);
	if (tmp->iswid && tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
