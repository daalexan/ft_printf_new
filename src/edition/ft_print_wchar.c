#include "ft_printf.h"

void	ft_print_2(unsigned int str)
{
	unsigned char	oct2;
	unsigned char	oct1;
	unsigned char   octet;
	unsigned int	mask1;
	unsigned int	mask2;

	mask1 = 49280;
	mask2 = 14712960;
	oct1 = ((str >> 6) << 27) >> 27;        
	oct2 = (str << 26) >> 26;
	octet = (mask1 >> 8) | oct1;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | oct2;
	write(1, &octet, 1);    
}

void	ft_print_3(unsigned int str)
{
	unsigned char	oct3;
	unsigned char	oct2;
    unsigned char	oct1;
	unsigned char	octet;
	unsigned int	mask2;
    
	mask2 = 14712960;
	oct3 = (str << 26) >> 26;
	oct2 = ((str >> 6) << 26) >> 26;
	oct1 = ((str >> 12) << 28) >> 28;

	octet = (mask2 >> 16) | oct1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | oct2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | oct3;
	write(1, &octet, 1);
}

void	ft_print_wchar(wchar_t str, unsigned int len)
{
    unsigned char   octet;
  
    if (len == 1)
    {
        octet = str;
        write(1, &octet, 1);
    }
    else if (len == 2)
    	ft_print_2(str);
	else if (len == 3)
		ft_print_3(str);
}									   
