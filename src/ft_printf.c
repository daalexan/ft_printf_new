/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:35:26 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:35:27 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_parse(char *format, int *i, va_list *arg)
{
	t_hndl	hndl;
	t_tmp	tmp;

	ft_bzero(&tmp, sizeof(tmp));
	while (format[*i])
	{
		ft_flag(format, i, &tmp);
		ft_width(format, i, arg, &tmp);
		ft_prs(format, i, arg, &tmp);
		ft_type(format, i, &tmp);
		if ((hndl = ft_init(format[*i])) != NULL)
			return (hndl(format, arg, i, &tmp));
		else
			(*i)++;
	}
	return (-1);
}

static int		ft_start(char *format, va_list *arg)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parse(format, &i, arg);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, format);
	res = ft_start((char*)format, &arg);
	va_end(arg);
	return (res);
}
