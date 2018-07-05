#include "ft_printf.h"

static size_t	ft_plen(wchar_t *str, int prs, size_t i)
{
	if (*str == '\0' || prs == 0)
		return (i);
	else if (*str <= 127)
		return (ft_plen(str + 1, prs - 1, i + 1));
	else if (*str <= 2047 && prs >= 2)
		return (ft_plen(str + 1, prs - 2, i + 2));
	else
		return (i);
}

static size_t ft_wlen(wchar_t *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		if (*str <= 127)
			len++;
		else if (*str <= 2047)
			len+= 2;
		str++;
	}
	return (len);
}

static void	ft_putwstr(wchar_t *str, ssize_t len)
{
	ssize_t i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 127)
			i++;
		else if (*str <= 2047)
			i += 2;
		if (i <= len)
		{
			if (*str <= 127)
				ft_print_wchar(*str, 1);
			else if (*str <= 2047)
				ft_print_wchar(*str, 2);
		}
		str++;
	}
}

ssize_t	ft_wstr_handle(char *frm, va_list *arg, int *i, t_tmp *tmp)
{
	ssize_t strlen;
	wchar_t *str;

	(void)frm;
	(void)i;
	str = va_arg(*arg, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = tmp->isprs ? ft_plen(str, tmp->prs, 0) : ft_wlen(str);
	if (tmp->iswid && !tmp->minus)
		ft_space(strlen, tmp->wid, ' ');
	ft_putwstr(str, strlen);
	if (tmp->iswid && tmp->minus)
		ft_space(strlen, tmp->wid, ' ');
	return (tmp->iswid ? FT_MAX(strlen, tmp->wid) : strlen);
}
