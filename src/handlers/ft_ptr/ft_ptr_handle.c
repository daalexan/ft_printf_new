#include "ft_printf.h"

ssize_t ft_ptr_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	size_t	nbr;
	
	(void)i;
	(void)frm;
	if (tmp->isprs)
		tmp->zero = 0;
	nbr = va_arg(*arg, size_t);
	tmp->hash = 1;
	return (ft_print_hex(nbr, tmp, "0x"));
}
