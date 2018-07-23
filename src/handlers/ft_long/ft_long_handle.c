#include "ft_printf.h"

ssize_t ft_long_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	tmp->type = 3;
	return (ft_unsig_handle(frm, arg, i, tmp));
}
