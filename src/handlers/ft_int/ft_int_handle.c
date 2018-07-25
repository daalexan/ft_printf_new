/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:08:18 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/24 19:08:19 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
