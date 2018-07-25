/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:17:01 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:17:02 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_long_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	tmp->type = 3;
	return (ft_unsig_handle(frm, arg, i, tmp));
}
