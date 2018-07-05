#include "ft_printf.h"

ssize_t	ft_octlen(uintmax_t nbr)
{
	ssize_t len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 8;
		len++;
	}
	return (len);
}
