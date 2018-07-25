/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:20:29 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:20:44 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_str_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	char	*str;
	ssize_t	strlen;

	(void)frm;
	(void)i;
	if (tmp->type == 3)
		return (0);
	else
	{
		str = va_arg(*arg, char*);
		if (str == NULL)
			str = "(null)";
		if (ft_strlen(str) == 0 && (tmp->wid != 0 || tmp->prs != 0))
		{
			ft_space(0, tmp->wid, ' ');
			return (tmp->wid);
		}
		strlen = tmp->isprs ? tmp->prs : (ssize_t)ft_strlen(str);
		if (tmp->iswid && !tmp->minus)
			ft_space(strlen, tmp->wid, tmp->zero ? '0' : ' ');
		ft_putnstr(str, strlen);
		if (tmp->iswid && tmp->minus)
			ft_space(strlen, tmp->wid, ' ');
		return (tmp->iswid ? tmp->wid : strlen);
	}
}
