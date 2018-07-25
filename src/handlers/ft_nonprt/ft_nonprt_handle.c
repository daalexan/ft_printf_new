/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonprt_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:33:13 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:33:15 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_nonprt_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	int		nbr;
	char	smb[32][4] = {
		"NULL", "SOH", "STX", "ETX", "EOT",
		"ENQ", "ACK", "BEL", "BS", "HT", "LF",
		"VT", "FF", "CR", "SO", "SI", "DLE", "DC1",
		"DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN",
		"EM", "SUB", "ESC", "FS", "GS", "RS", "US"
	};
	(void)i;
	(void)frm;
	(void)tmp;
	nbr = va_arg(*arg, int);
	ft_putstr(smb[nbr]);
	return (ft_strlen(smb[nbr]));
}
