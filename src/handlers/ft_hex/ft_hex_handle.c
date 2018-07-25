/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:18:45 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:18:46 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_hex_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	if (tmp->isprs)
		tmp->zero = 0;
	if (frm[*i] == 'X')
		return (ft_print_hex(arg, tmp, "0X"));
	else
		return (ft_print_hex(arg, tmp, "0x"));
}
