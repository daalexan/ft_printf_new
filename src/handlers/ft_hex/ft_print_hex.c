/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:18:35 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:18:36 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_length(t_tmp *tmp, ssize_t len)
{
	if (tmp->isprs)
	{
		if (tmp->prs > len)
			len = tmp->prs;
	}
	if (tmp->hash)
		len += 2;
	if (tmp->space || tmp->plus)
		len++;
	return (len);
}

ssize_t			ft_print_hex(va_list *arg, t_tmp *tmp, char *hex)
{
	ssize_t		nbrstr;
	ssize_t		nbrlen;
	intmax_t	nbr;

	nbr = convert(arg, tmp);
	if (nbr == 0)
		tmp->hash = 0;
	nbrstr = ft_hexlen(nbr);
	if (tmp->isprs)
		if (tmp->prs == 0)
			nbrstr = 0;
	ft_peref(nbrstr, tmp);
	nbrlen = ft_length(tmp, nbrstr);
	if (tmp->iswid && !tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	if (tmp->hash)
		ft_putstr(hex);
	ft_puthexsymb(nbr, tmp, nbrstr, hex);
	if (tmp->iswid && tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	if (tmp->isprs)
		if (tmp->prs == 0)
			nbrlen = 0;
	return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
