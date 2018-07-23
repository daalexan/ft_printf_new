#include "ft_printf.h"

ssize_t	ft_dint_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	tmp->type = 3;
	return (ft_int_handle(frm, arg, i, tmp));
}
