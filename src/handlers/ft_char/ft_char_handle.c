/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:27:40 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:27:41 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_char_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	if (tmp->type == 3)
		return (ft_wchar_handle(frm, arg, i, tmp));
	else
	{
		if (tmp->iswid && !tmp->minus)
			ft_space(1, tmp->wid, tmp->zero ? '0' : ' ');
		ft_putchar(va_arg(*arg, int));
		if (tmp->iswid && tmp->minus)
			ft_space(1, tmp->wid, ' ');
		return (tmp->iswid ? FT_MAX(tmp->wid, 1) : 1);
	}
}
