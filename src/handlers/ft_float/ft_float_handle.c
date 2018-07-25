/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:30:04 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:30:05 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_func(double *nbr, t_tmp *tmp, size_t *len)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		ft_putchar('-');
		(*len)++;
	}
	if (tmp->type == 8)
		*nbr = (long double)*nbr;
}

ssize_t		ft_float_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	double	nbr;
	ssize_t	start;
	ssize_t	end;
	size_t	len;

	len = 0;
	nbr = va_arg(*arg, double);
	if (frm[*i] == 'F')
		tmp->type = 8;
	ft_func(&nbr, tmp, &len);
	start = nbr;
	len += ft_nbrlen(start) + 1;
	ft_putfloat(start);
	ft_putchar('.');
	nbr -= start;
	end = nbr * ft_wide(tmp) + 0.5;
	len += ft_nbrlen(end);
	ft_putfloat(end);
	return (len);
}
