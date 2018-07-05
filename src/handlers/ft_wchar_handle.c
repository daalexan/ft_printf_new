#include "ft_printf.h"

static unsigned ft_size(wchar_t symb)
{
	unsigned len;

	if (symb <= 127)
		len = 1;
	else if (symb <= 2047)
		len = 2;
	else if (symb <= 65535)
		len = 3;
	else if (symb <= 1114111)
		len = 4;
	else
		len = 0;
	return (len);
}

ssize_t	ft_wchar_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	wchar_t str;
	unsigned int strlen;
	
	(void)i;
	(void)frm;
	str = (wchar_t)va_arg(*arg, wint_t);
	strlen = ft_size(str);
	if (tmp->iswid && !tmp->minus)
		ft_space(strlen, tmp->wid, tmp->zero ? '0' : ' ');
	ft_print_wchar(str, strlen);
	if (tmp->iswid && tmp->minus)
		ft_space(strlen, tmp->wid, tmp->zero ? '0' : ' ');
	return (tmp->iswid ? FT_MAX(strlen, tmp->wid) : strlen);
}
