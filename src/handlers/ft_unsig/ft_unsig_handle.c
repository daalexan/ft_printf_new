/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:14:55 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/24 19:14:56 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	conv(va_list *arg, t_tmp *tmp)
{
	uintmax_t nbr;

	nbr = 0;
	if (tmp->type == 1)
		nbr = (unsigned char)va_arg(*arg, int);
	else if (tmp->type == 2)
		nbr = (unsigned short int)va_arg(*arg, int);
	else if (tmp->type == 3)
		nbr = (unsigned long int)va_arg(*arg, long int);
	else if (tmp->type == 4)
		nbr = (unsigned long long int)va_arg(*arg, long long int);
	else if (tmp->type == 5)
		nbr = (uintmax_t)va_arg(*arg, intmax_t);
	else if (tmp->type == 6)
		nbr = (size_t)va_arg(*arg, size_t);
	else
		nbr = (unsigned int)va_arg(*arg, int);
	return (nbr);
}

static void		ft_putunsig(uintmax_t nbr)
{
	char *num;

	num = "0123456789";
	if (nbr >= 10)
	{
		ft_putunsig(nbr / 10);
		ft_putunsig(nbr % 10);
	}
	else
		ft_putchar(num[nbr]);
}

static void		ft_putsymb(uintmax_t nbr, t_tmp *tmp, unsigned len)
{
	if (tmp->isprs)
		ft_space(len, tmp->prs, '0');
	if (nbr == 0 && tmp->isprs && tmp->prs == 0)
		return ;
	else
		ft_putunsig(nbr);
}

static ssize_t	ft_length(t_tmp *tmp, ssize_t len)
{
	if (tmp->isprs)
	{
		if (tmp->prs > len)
			len = tmp->prs;
		if (tmp->prs == 0)
			len = 0;
	}
	return (len);
}

static ssize_t	ft_nbr(unsigned long long nbr)
{
	ssize_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

ssize_t			ft_unsig_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	intmax_t	nbr;
	ssize_t		nbrlen;
	ssize_t		nbrstr;

	(void)frm;
	(void)i;
	nbr = conv(arg, tmp);
	nbrstr = ft_nbr(nbr);
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
	ft_putsymb(nbr, tmp, nbrstr);
	if (tmp->iswid && tmp->minus)
		ft_space(nbrlen, tmp->wid, ' ');
	return (tmp->iswid ? FT_MAX(tmp->wid, nbrlen) : nbrlen);
}
