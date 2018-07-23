#include "ft_printf.h"

static void	ft_setinit(t_hndl *hndl)
{	
	hndl['s'] = &ft_str_handle;
	hndl['S'] = &ft_wstr_handle;
	hndl['d'] = &ft_int_handle;
	hndl['D'] = &ft_dint_handle;
	hndl['i'] = &ft_int_handle;
	hndl['c'] = &ft_char_handle;
	hndl['C'] = &ft_wchar_handle;
	hndl['X'] = &ft_hex_handle;
	hndl['x'] = &ft_hex_handle;
	hndl['u'] = &ft_unsig_handle;
	hndl['U'] = &ft_long_handle;
	hndl['o'] = &ft_octal_handle;
	hndl['O'] = &ft_octal_handle;
	hndl['n'] = &ft_nth_handle;
	hndl['b'] = &ft_binary_handle;
	hndl['p'] = &ft_ptr_handle;
	hndl['f'] = &ft_float_handle;
	hndl['F'] = &ft_float_handle;
	hndl['e'] = &ft_scinot_handle;
	hndl['E'] = &ft_scinot_handle;
}

t_hndl	ft_init(char c)
{
	t_hndl *hndl;
	t_hndl ret;

	if ((hndl = malloc(sizeof(*hndl) *256)))
			ft_setinit(hndl);
	ret = hndl[(int)c];
	free(hndl);
	return (ret);
}
