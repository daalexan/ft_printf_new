/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:34:26 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:18:57 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(uintmax_t nbr, char c)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, c);
	if (nbr % 16 < 10)
		ft_putchar((nbr % 16) + '0');
	else
		ft_putchar((nbr % 16) - 10 + c);
}

void	ft_puthexsymb(uintmax_t nbr, t_tmp *tmp,\
		unsigned len, char *hex)
{
	if (hex == NULL)
		return ;
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

ssize_t	ft_hexlen(uintmax_t nbr)
{
	ssize_t len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_peref(ssize_t nbr, t_tmp *tmp)
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
