#include "ft_printf.h"

ssize_t ft_str_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
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
		strlen = tmp->isprs ? tmp->prs : (ssize_t)ft_strlen(str);
		if (tmp->iswid && !tmp->minus)
			ft_space(strlen, tmp->wid, tmp->zero ? '0' : ' ');
		ft_putnstr(str, strlen);
		if (tmp->iswid && tmp->minus)
			ft_space(strlen, tmp->wid, ' ');
		return (tmp->iswid ? tmp->wid : strlen);
	}
}
