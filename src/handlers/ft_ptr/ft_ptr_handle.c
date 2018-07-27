/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:22:24 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:22:26 by daalexan         ###   ########.fr       */
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
	return (len);
}

static ssize_t	ft_print(va_list *arg, t_tmp *tmp, char *hex)
{
	ssize_t		nbrstr;
	ssize_t		nbrlen;
	intmax_t	nbr;

	nbr = convert(arg, tmp);
	nbrstr = ft_hexlen(nbr);
	if (tmp->isprs)
		if (tmp->prs == 0)
			nbrstr = 0;
	ft_peref(nbrstr, tmp);
	nbrlen = ft_length(tmp, nbrstr);
	if (tmp->iswid && !tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	ft_putstr(hex);
	ft_puthexsymb(nbr, tmp, nbrstr, hex);
	if (tmp->iswid && tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}

ssize_t			ft_ptr_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	(void)i;
	(void)frm;
	tmp->type = 6;
	if (tmp->isprs)
		tmp->zero = 0;
	tmp->hash = 1;
	return (ft_print(arg, tmp, "0x"));
}
