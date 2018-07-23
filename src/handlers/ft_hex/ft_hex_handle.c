#include "ft_printf.h"

ssize_t	ft_hex_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	intmax_t	nbr;
	
	if (tmp->isprs)
		tmp->zero = 0;
	nbr = convert(arg, tmp);
	if (frm[*i] == 'X')
		return (ft_print_hex(nbr, tmp, "0X"));
	else
		return (ft_print_hex(nbr, tmp, "0x"));
}
