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
# define FT_MAX(x,y) ((x >= y) ? x : y)

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
void                ft_space(ssize_t len, int width, char symb);
ssize_t			ft_nbrlen(ssize_t n);
ssize_t			ft_octlen(uintmax_t nbr);
void                ft_putn(uintmax_t n, size_t len);
ssize_t			ft_print_hex(va_list *arg, t_tmp *tmp, char *hex);
uintmax_t           convert(va_list *arg, t_tmp *tmp);
void                ft_print_wchar(wchar_t str, unsigned int len);
ssize_t			ft_print_int(uintmax_t nbr, t_tmp *tmp);
void                ft_putint(uintmax_t nbr);
intmax_t		     convert_type(va_list *arg, t_tmp *tmp);
ssize_t             ft_wide(t_tmp *tmp);
void                ft_putfloat(ssize_t nbr);
void                ft_puthex(uintmax_t nbr, char c);
void                ft_puthexsymb(uintmax_t nbr, t_tmp *tmp,unsigned len, char *hex);
ssize_t             ft_hexlen(uintmax_t nbr);
void                ft_peref(ssize_t nbr, t_tmp *tmp);

/*
**	handlers functions
*/
ssize_t			ft_str_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t 		     ft_int_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
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
ssize_t			ft_dint_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_binary_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_ptr_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_float_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_scinot_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t			ft_nonprt_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);
ssize_t             ft_prsnt_handle(char *frm, va_list *arg, int *i, t_tmp *tmp);


#endif
