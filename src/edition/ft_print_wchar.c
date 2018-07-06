#include "ft_printf.h"

static void	ft_print_2(unsigned int str, unsigned char octet)
{
	unsigned char	oct2;
	unsigned char	oct1;
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

static void	ft_print_3(unsigned int str, unsigned char octet)
{
	unsigned char	oct3;
	unsigned char	oct2;
    unsigned char	oct1;
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

static void ft_print_4(unsigned int str, unsigned char octet)
{
	unsigned int	mask3;
	unsigned char	oct4;
	unsigned char	oct3;
	unsigned char	oct2;
	unsigned char	oct1;

	oct4 = (str << 26) >> 26;
	oct3 = ((str >> 6) << 26) >> 26;
	oct2 = ((str >> 12) << 26) >> 26;
	oct1 = ((str >> 18) << 29) >> 29;
	mask3 = 4034953344;
	octet = (mask3 >> 24) | oct1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | oct2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | oct3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | oct4;
	write(1, &octet, 1);
}

void	ft_print_wchar(wchar_t str, unsigned int len)
{
    unsigned char   octet;
  
	octet = str;
    if (len == 1)
        write(1, &octet, 1);
    else if (len == 2)
    	ft_print_2(str, octet);
	else if (len == 3)
		ft_print_3(str, octet);
	else if (len == 4)
		ft_print_4(str, octet);
}									   
