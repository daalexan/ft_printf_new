/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsnt_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:52:40 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/24 13:52:43 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_length(t_tmp *tmp, ssize_t len)
{
	if (tmp->wid)
		if (tmp->wid > len)
			len = tmp->wid;
	return (len);
}

ssize_t			ft_prsnt_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	ssize_t	nbrstr;
	ssize_t	nbrlen;

	(void)frm;
	(void)i;
	(void)arg;
	nbrstr = 1;
	if (tmp->iswid && !tmp->minus && tmp->zero)
	{
		ft_space(1, tmp->wid, '0');
		ft_putchar('%');
		return (tmp->wid);
	}
	nbrlen = ft_length(tmp, nbrstr);
	if (tmp->iswid && !tmp->minus)
		ft_space(nbrstr, tmp->wid, ' ');
	ft_putchar('%');
	if (tmp->iswid && tmp->minus)
		ft_space(nbrstr, tmp->wid, ' ');
	return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
