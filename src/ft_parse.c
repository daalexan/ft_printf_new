#include "ft_printf.h"

void	ft_flag(char *frm, int *i, t_tmp *tmp)
{
	if (frm[*i] == '-' || frm[*i] == '+' || frm[*i] == ' ' ||
			frm[*i] == '#' || frm[*i] == '0')
	{
		if (frm[*i] == '-')
			tmp->minus = 1;
		else if (frm[*i] == '+')
			tmp->plus = 1;
		else if (frm[*i] == ' ')
			tmp->space = 1;
		else if (frm[*i] == '#')
			tmp->hash = 1;
		else if (frm[*i] == '0')
			tmp->zero = 1;
		if (tmp->minus)
			tmp->zero = 0;	
	}
}

void	ft_width(char *frm, int *i, va_list *arg, t_tmp *tmp)
{
	int wid;

	tmp->wid = 0;
	if (frm[*i] == '*' || ft_isdigit(frm[*i]))
	{
		if (frm[*i] == '*')
		{
			(*i)++;
			wid = va_arg(*arg, int);
			if (wid < 0)
				tmp->minus = 1;
			tmp->wid = wid < 0 ? -wid : wid;
			tmp->iswid = 1;
			return ;
		}
		if (ft_isdigit(frm[*i]))
		{
			tmp->iswid = 1;
			tmp->wid = 0;
			while (ft_isdigit(frm[*i]))
				tmp->wid = tmp->wid * 10 + frm[(*i)++] - '0';
		}
	}
}

void	ft_prs(char *frm, int *i, va_list *arg, t_tmp *tmp)
{
	int prs;

	if (frm[*i] == '.')
	{
		(*i)++;
		if (frm[*i] == '*')
		{
			(*i)++;
			if ((prs = va_arg(*arg, int)) >= 0)
			{
				tmp->isprs = 1;
				tmp->prs = prs;
			}
		}
		else
		{
			while (ft_isdigit(frm[*i]))
				tmp->prs = tmp->prs * 10 + frm[(*i)++] - '0';
			tmp->isprs = 1;
		}
	}
}

void	ft_type(char *frm, int *i, t_tmp *tmp)
{
	if (frm[*i] == 'h')
	{
		if (tmp->type == 0)
			tmp->type = 2;
		else if (tmp->type == 2)
			tmp->type = 1;
	}
	else if (frm[*i] == 'l')
	{
		if (tmp->type == 0)
			tmp->type = 3;
		else if (tmp->type == 3)
			tmp->type = 4;
	}
	else if (frm[*i] == 'j')
		tmp->type = 5;
	else if (frm[*i] == 'z')
		tmp->type = 6;
}

