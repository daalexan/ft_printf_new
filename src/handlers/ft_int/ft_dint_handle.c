/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dint_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:08:04 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/24 19:08:06 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_dint_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	tmp->type = 3;
	return (ft_int_handle(frm, arg, i, tmp));
}
