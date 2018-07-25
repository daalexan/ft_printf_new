/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:09:14 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 11:09:16 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space(ssize_t len, int width, char symb)
{
	ssize_t line;

	line = (ssize_t)(width - len);
	while (line > 0)
	{
		ft_putchar(symb);
		line--;
	}
}
