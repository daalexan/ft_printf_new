#include "ft_printf.h"

uintmax_t convert(va_list *arg, t_tmp *tmp)
{
	uintmax_t nbr;

	nbr = va_arg(*arg, uintmax_t);
	if (tmp->type == 1)
        nbr = (unsigned char)nbr;
    else if (tmp->type == 2)
        nbr = (unsigned short int)nbr;
    else if (tmp->type == 3)
        nbr = (unsigned long int)nbr;
    else if (tmp->type == 4)
		nbr = (unsigned long long int)nbr;
    else if (tmp->type == 5)
        nbr = (uintmax_t)nbr;
    else if (tmp->type == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;  
	return (nbr);
}
