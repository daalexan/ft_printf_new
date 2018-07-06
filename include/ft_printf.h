#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# define FT_MAX(x,y) (x >= y) ? x : y

typedef struct  s_tmp
{
     short		minus;
     short		plus;
     short		space;
     short		zero;
     short		hash;
     ssize_t	wid;
     short		iswid;
	 ssize_t	prs;
     short		isprs;
     char		type;
}               t_tmp;

int				ft_printf(const char *format, ...);

typedef	ssize_t	(*t_hndl)(char*, va_list*, int*, t_tmp*);
/*
**	parse functions
*/
void			ft_flag(char *frm, int *i, t_tmp *tmp);
void			ft_width(char *frm, int *i, va_list *arg, t_tmp *tmp);
void			ft_prs(char *frm, int *i, va_list *arg, t_tmp *tmp);
void			ft_type(char *frm, int *i, t_tmp *tmp);
/*
**	edition functions
*/
void    		ft_space(ssize_t len, int width, char symb);
size_t			ft_nbrlen(int n);
ssize_t			ft_octlen(uintmax_t nbr);
void			ft_putn(uintmax_t n, size_t len);
ssize_t			ft_print_hex(intmax_t nbr, t_tmp *tmp, char *hex);
uintmax_t		convert(va_list *arg, t_tmp *tmp);
void			ft_print_wchar(wchar_t str, unsigned int len);
/*
**	handlers functions
*/
ssize_t			ft_str_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t 		ft_int_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_pref_handle(uintmax_t nbr, char *pref, t_tmp *tmp);
ssize_t			ft_char_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
t_hndl			ft_init(char c);
ssize_t			ft_hex_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_unsig_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_long_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_octal_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_wchar_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_wstr_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_nth_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);

#endif
