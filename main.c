#include "./include/ft_printf.h"
#include <locale.h>
#include "limits.h"
int main()
{

	setlocale(LC_ALL, "");
	/*
	   specifier %d is handled
	*/
/*	printf("My %d\n", ft_printf("My|%5.7d| |%+-6.4d| |%+6.4d| |%4.6d| |%.5d| |%06d| |%+06d| |%0 +6d| |%0+ 6d| |%6d| |%+-6.4d| |%+-4.6d| |%+-4.6d|\n", 42, 345, 345, -345, -345, -345,-345, -345, -345, -345, 345, 345, -345));
	printf("Or %d\n", 	 printf("Or|%5.7d| |%+-6.4d| |%+6.4d| |%4.6d| |%.5d| |%06d| |%+06d| |%0 +6d| |%0+ 6d| |%6d| |%+-6.4d| |%+-4.6d| |%+-4.6d|\n", 42, 345, 345, -345, -345, -345,-345, -345, -345, -345, 345, 345, -345));
	printf("My %d\n", ft_printf("My|%+-6.4d|\n", 345));
	printf("Or %d\n", 	 printf("Or|%+-6.4d|\n", 345));
	printf("My %d\n", ft_printf("My|%+6.4d|\n", 345));
	printf("Or %d\n",	 printf("Or|%+6.4d|\n", 345));
	printf("My %d\n", ft_printf("My|%4.6d|\n", -345));
	printf("Or %d\n",    printf("Or|%4.6d|\n", -345));
	printf("My %d\n", ft_printf("My|%.5d|\n", -345));
	printf("Or %d\n", 	 printf("Or|%.5d|\n", -345));
	printf("My %d\n", ft_printf("My|%06d|\n", -345));
	printf("Or %d\n",    printf("Or|%06d|\n", -345));
	printf("My %d\n", ft_printf("My|%+06d|\n", -345));
	printf("Or %d\n",    printf("Or|%+06d|\n", -345));
	printf("My %d\n", ft_printf("My|%0 +6d|\n", -345));
    printf("Or %d\n",    printf("Or|%0 +6d|\n", -345));
	printf("My %d\n", ft_printf("My|%0+ 6d|\n", -345));
	printf("Or %d\n",    printf("Or|%0+ 6d|\n", -345));
	printf("My %d\n", ft_printf("My|%6d|\n", -345));
 	printf("Or %d\n",    printf("Or|%6d|\n", -345));
	printf("My %d\n", ft_printf("My|%+-6.4d|\n", 345));
	printf("Or %d\n",    printf("Or|%+-6.4d|\n", 345));
	printf("My %d\n", ft_printf("My|%+-4.6d|\n", 345));
	printf("Or %d\n",    printf("Or|%+-4.6d|\n", 345));
	printf("My %d\n", ft_printf("My|%+-4.6d|\n", -345));
	printf("Or %d\n",    printf("Or|%+-4.6d|\n", -345));
*/
	/*
	   specifier %o is handled
	*/
/*	printf("My %d\n", ft_printf("My|%#5o| |%+-04.0o| |%#-5.4o| |%#5.4o| |%5.4o| |%#05o|\n", 345, 0, 345, 345, 345, 345));
	printf("Or %d\n",    printf("Or|%#5o| |%+-04.0o| |%#-5.4o| |%#5.4o| |%5.4o| |%#05o|\n", 345, 0, 345, 345, 345, 345));
	printf("My %d\n", ft_printf("My|%#5o|\n", 345));
	printf("Or %d\n",    printf("Or|%#5o|\n", 345));
	printf("My %d\n", ft_printf("My|%+-04.0o|\n", 0));
	printf("Or %d\n",    printf("Or|%+-04.0o|\n", 0));
	printf("My %d\n", ft_printf("My|%#-5.4o|\n", 345));
	printf("Or %d\n",    printf("Or|%#-5.4o|\n", 345));
	printf("My %d\n", ft_printf("My|%#5.4o|\n", 345));
	printf("Or %d\n",    printf("Or|%#5.4o|\n", 345));
	printf("My %d\n", ft_printf("My|%5.4o|\n", 345));
	printf("Or %d\n",    printf("Or|%5.4o|\n", 345));
	printf("My %d\n", ft_printf("My|%#05o|\n", 345));
	printf("Or %d\n",    printf("Or|%#05o|\n", 345));

	printf("My %d\n", ft_printf("My|%#-16O|\n",  345345345));
	printf("Or %d\n",    printf("Or|%#-16lo|\n", 345345345));
	printf("My %d\n", ft_printf("My|%#-16lo|\n", 345345345));
	printf("Or %d\n",    printf("Or|%#-16lo|\n", 345345345));
*/
	/*
	   specifier %D is handled
	*/
	
/*
	printf("My %d\n", ft_printf("My|%+-6.4D|\n",  345345345345));
    printf("Or %d\n",    printf("Or|%+-6.4ld|\n", 345345345345));
    printf("My %d\n", ft_printf("My|%+6.4D|\n",   345345345345));
    printf("Or %d\n",    printf("Or|%+6.4ld|\n",  345345345345));
	printf("My %d\n", ft_printf("My|%14.16ld|\n", 	  345345345345));
    printf("Or %d\n",    printf("Or|%14.16ld|\n",   345345345345));
    printf("My %d\n", ft_printf("My|%-016ld|\n", 	  345345345345));
    printf("Or %d\n",    printf("Or|%-016ld|\n",    345345345345));
	printf("My %d\n", ft_printf("My|%-016ld|\n",     345345345345));
	printf("Or %d\n",    printf("Or|%0-16ld|\n", 	  345345345345));
    printf("My %d\n", ft_printf("My|%+06d|\n", -345));
    printf("Or %d\n",    printf("Or|%+06d|\n", -345));
    printf("My %d\n", ft_printf("My|%0 +6d|\n", -345));
    printf("Or %d\n",    printf("Or|%0 +6d|\n", -345));
    printf("My %d\n", ft_printf("My|%0+ 6d|\n", -345));
    printf("Or %d\n",    printf("Or|%0+ 6d|\n", -345));
    printf("My %d\n", ft_printf("My|%6d|\n", -345));
    printf("Or %d\n",    printf("Or|%6d|\n", -345));
    printf("My %d\n", ft_printf("My|%+-6.4d|\n", 345));
    printf("Or %d\n",    printf("Or|%+-6.4d|\n", 345));
    printf("My %d\n", ft_printf("My|%+-4.6d|\n", 345));
    printf("Or %d\n",    printf("Or|%+-4.6d|\n", 345));
    printf("My %d\n", ft_printf("My|%+-4.6d|\n", -345));
    printf("Or %d\n",    printf("Or|%+-4.6d|\n", -345));

	ft_printf("binary %016b\n", 345345);
	printf("new line %7.6p\n", (void*)234);
	ft_printf("my new %7.6p\n", (void*)234);
*/
	/*
		specifier %f is handled
	*/
/*
	printf("Or %d\n", 	 printf("or %03f\n", 34.2345));
	printf("My %d\n", ft_printf("my %03f\n", 34.2345));
	printf("Or %d\n", 	 printf("or %6.3f\n", 34.234523));
	printf("My %d\n", ft_printf("my %6.3f\n", 34.234523));
	printf("Or %d\n", 	 printf("or %.15f\n", 34.1234567892));
	printf("My %d\n", ft_printf("my %.15f\n", 34.1234567892));
	printf("Or %d\n", 	 printf("or %.1f\n", 34.2345));
	printf("My %d\n", ft_printf("my %.1f\n", 34.2345));
	printf("Or %d\n", 	 printf("or %06f\n", -34.2345));
	printf("My %d\n", ft_printf("my %06f\n", -34.2345));
	printf("Or %d\n", 	 printf("or %.18Lf\n", 0.333333333333333333L));
	printf("My %d\n", ft_printf("my %.18Lf\n", 0.333333333333333333));
	printf("Or %d\n", 	 printf("or %.18Lf\n", 0.333333333333333333L));
	printf("My %d\n", ft_printf("my %.18F\n", 0.333333333333333333));
*/
	/*
		specifier %e is handled
	*/

/*	printf("Or %d\n", 	 printf("or %6.4e\n", 1.234532532434));
	printf("My %d\n", ft_printf("my %6.4e\n", 1.234532532434));
	printf("Or %d\n", 	 printf("or %E\n", 0.000000000123));
	printf("My %d\n", ft_printf("my %E\n", 0.000000000123));
	printf("Or %d\n", 	 printf("or %.4e\n", -32345325324.34));
	printf("My %d\n", ft_printf("my %.4e\n", -32345325324.34));
	printf("Or %d\n", 	 printf("or %E\n", -0.000000000123));
	printf("My %d\n", ft_printf("my %E\n", -0.000000000123));
	printf("Or %d\n", 	 printf("or %.4E\n", 32345325324.34));
	printf("My %d\n", ft_printf("my %.4E\n", 32345325324.34));
	printf("testing new specifier\n");
	printf("Or %d\n", 	 printf("or %e\n", 323453.34));
	printf("My %d\n", ft_printf("my %e\n", 323453.34));
	printf("Or %d\n", 	 printf("or %f\n", 323453.34));
	printf("My %d\n", ft_printf("my %f\n", 323453.34));

*/
	
	/*
		specifier %S is handled
	*/
/*	printf("Or %d\n", 	 printf("or %ls\n",   L"ϢѴѼӨ"));
	printf("My %d\n", ft_printf("my %S\n",	  L"ϢѴѼӨ"));
	printf("Or %d\n", 	 printf("or %.5ls\n", L"ϢѴѼӨ"));
	printf("My %d\n", ft_printf("my %.5S\n",  L"ϢѴѼӨ"));
	printf("Or %d\n", 	 printf("or %15ls\n", L"Ϣ ѴѼ Ө"));
	printf("My %d\n", ft_printf("my %15S\n",  L"Ϣ ѴѼ Ө"));
	printf("Or %d\n", 	 printf("or %lc\n", 934));
	printf("My %d\n", ft_printf("my %C\n", 934));
	printf("Or %d\n", 	 printf("or %ls\n", L"привет"));
	printf("My %d\n", ft_printf("my %S\n",  L"привет"));
	
	printf("My %d\n", ft_printf("my %r\n", NULL));
	printf("My %d\n", ft_printf("my %r\n", '\t'));
*/
	//ft_printf("%5%");
	//printf("len = %d\n", ft_printf("%U", 4294967296));

	printf("Start testing original mulitest\n");
/*
	printf("Testing specifier %%\n");
	printf("My %d\n", ft_printf("%5%\n"));         //  -> "    %"
	printf("Or %d\n", 	 printf("%5%\n"));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-5%\n"));        // -> "%    "
	printf("Or %d\n", 	 printf("%-5%\n"));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%.0%\n"));          // -> "%"
	printf("Or %d\n", 	 printf("%.0%\n")); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%.0%\n", "test"));     //   -> "%" 
	printf("Or %d\n", 	 printf("%.0%\n", "test"));
	printf("<------>\n");
	*/
	
	/*
	printf("Testing specifier %x\n");
	printf("My %d\n", ft_printf("%x\n", 42));                        //  -> "2a"
	printf("Or %d\n", 	 printf("%x\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%X\n", 42));                         // -> "2A"
	printf("Or %d\n", 	 printf("%X\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%x\n", 0));                         //  -> "0"
	printf("Or %d\n", 	 printf("%x\n", 0)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%X\n", 0));                          // -> "0"
	printf("Or %d\n", 	 printf("%X\n", 0));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%x\n", -42));                        // -> "ffffffd6"
	printf("Or %d\n", 	 printf("%x\n", -42)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%X\n", -42));                        // -> "FFFFFFD6"
	printf("Or %d\n", 	 printf("%X\n", -42)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%x\n", 4294967296));                 // -> "0"
	printf("Or %d\n", 	 printf("%x\n", 4294967296));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%X\n", 4294967296));                	 // -> "0"
	printf("Or %d\n", 	 printf("%X\n", 4294967296)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%10x\n", 42));                       // -> "        2a"
	printf("Or %d\n", 	 printf("%10x\n", 42)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%lx\n", 4294967296));                // -> "100000000" not working
	printf("Or %d\n", 	 printf("%lx\n", 4294967296));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%llX\n", 4294967296));               // -> "100000000"
	printf("Or %d\n", 	 printf("%llX\n", 4294967296));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%hx\n", 4294967296));                // -> "0"
	printf("Or %d\n", 	 printf("%hx\n", 4294967296));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%hhX\n", 4294967296));               // -> "0"
	printf("Or %d\n", 	 printf("%hhX\n", 4294967296));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%jx\n", 4294967295));                // -> "ffffffff"
	printf("Or %d\n", 	 printf("%jx\n", 4294967295));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%jx\n", -4294967296));               // -> "ffffffff00000000"
	printf("Or %d\n", 	 printf("%jx\n", -4294967296)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%jx\n", -4294967297));               // -> "fffffffeffffffff"
	printf("Or %d\n", 	 printf("%jx\n", -4294967297));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%llx\n", 9223372036854775807));      // -> "7fffffffffffffff"
	printf("Or %d\n", 	 printf("%llx\n", 9223372036854775807));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%llx\n", 9223372036854775808));      // -> "7fffffffffffffff"
	printf("Or %d\n", 	 printf("%llx\n", 9223372036854775808));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%010x\n", 542));                   // -> "000000021e"
	printf("Or %d\n", 	 printf("%010x\n", 542));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-15x", 542)); 						// -> "21e            "
	printf("Or %d\n", 	printf("%-15x", 542));
	printf("<------>\n");                     
	printf("My %d\n", ft_printf("%2x\n", 542));                       // -> "21e"
	printf("Or %d\n", 	 printf("%2x\n", 542));
	printf("<------>\n");	 
	printf("My %d\n", ft_printf("%.2x\n", 5427));                     // -> "1533"
	printf("Or %d\n", 	 printf("%.2x\n", 5427)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%5.2x\n", 5427));                    // -> " 1533"
	printf("Or %d\n", 	 printf("%5.2x\n", 5427));   
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#x\n", 42));                        // -> "0x2a"
	printf("Or %d\n", 	 printf("%#x\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#llx\n", 9223372036854775807));     // -> "0x7fffffffffffffff"
	printf("Or %d\n", 	 printf("%#llx\n", 9223372036854775807));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#x\n", 0));                         // -> "0"
	printf("Or %d\n", 	 printf("%#x\n", 0)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#x\n", 42));                        // -> "0x2a"
	printf("Or %d\n", 	 printf("%#x\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#X\n", 42));                        // -> "0X2A"
	printf("Or %d\n", 	 printf("%#X\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#8x\n", 42));                       // -> "    0x2a"
	printf("Or %d\n", 	 printf("%#8x\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#08x\n", 42));                      // -> "0x00002a"
	printf("Or %d\n", 	 printf("%#08x\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%#-08x\n", 42));                     // -> "0x2a    "
	printf("Or %d\n", 	 printf("%#-08x\n", 42)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("@moulitest: %#.x %#.0x", 0, 0));   // -> "@moulitest:  "
	printf("Or %d\n", 	 printf("@moulitest: %#.x %#.0x", 0, 0));
	printf("<------>\n");
	printf("My %d\n", ft_printf("@moulitest: %5.x %5.0x", 0, 0));   // -> "@moulitest:            "
	printf("Or %d\n", 	 printf("@moulitest: %5.x %5.0x", 0, 0));
	printf("<------>\n");
	*/
/*
	printf("Testing specifier %x\n");
	printf("My %d\n", ft_printf("%.5s is a string\n", ""));           // -> " is a string"
	printf("Or %d\n", 	 printf("%.5s is a string\n", ""));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%5.2s is a string\n", ""));          // -> "      is a string"
	printf("Or %d\n", 	 printf("%5.2s is a string\n", ""));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-10s is a string\n", "this"));      // -> "this       is a string"
	printf("Or %d\n", 	 printf("%-10s is a string\n", "this"));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-.2s is a string\n", "this"));      // -> "th is a string"
	printf("Or %d\n", 	 printf("%-.2s is a string\n", "this"));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-5.2s is a string\n", "this"));     // -> "th    is a string"
	printf("Or %d\n", 	 printf("%-5.2s is a string\n", "this")); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-10s is a string\n", ""));          // -> "           is a string"
	printf("Or %d\n", 	 printf("%-10s is a string\n", ""));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-.2s is a string\n", ""));          // -> " is a string"
	printf("Or %d\n", 	 printf("%-.2s is a string\n", ""));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-5.2s is a string\n", ""));         // -> "      is a string"
	printf("Or %d\n", 	 printf("%-5.2s is a string\n", "")); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%s %s\n", "this", "is"));            // -> "this is"
	printf("Or %d\n", 	 printf("%s %s\n", "this", "is"));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%s %s %s\n", "this", "is", "a"));    // -> "this is a"
  	printf("Or %d\n", 	 printf("%s %s %s\n", "this", "is", "a"));
  	printf("<------>\n");
  	printf("My %d\n", ft_printf("%.4s", "42"));
 	printf("Or %d\n", 	 printf("%.4s", "42"));
 	printf("<------>\n");
  	*//*
	printf("My %d\n", ft_printf("%0+5d\n", 42));                      // -> "+0042"
	printf("Or %d\n", 	 printf("%0+5d\n", 42));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%lld\n", -9223372036854775808));     // -> "-9223372036854775808"
	printf("Or %d\n", 	 printf("%lld\n", -9223372036854775808)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%jd\n", -9223372036854775808));      // -> "-9223372036854775808"
	printf("Or %d\n", 	 printf("%jd\n", -9223372036854775808)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("@moulitest: %.d %.0d\n", 0, 0));    //  -> "@moulitest:  "
	printf("Or %d\n", 	 printf("@moulitest: %.d %.0d\n", 0, 0));
	printf("<------>\n");
	printf("My %d\n", ft_printf("@moulitest: %5.d %5.0d\n", 0, 0));  //  -> "@moulitest:            "
	printf("Or %d\n", 	 printf("@moulitest: %5.d %5.0d\n", 0, 0));
	printf("<------>\n");
	*/
	/*
	printf("Testing specifier %u\n");
	printf("My %d\n", ft_printf("%u\n", 0));                        //   -> "0"
 	printf("Or %d\n", 	 printf("%u\n", 0));
 	printf("<------>\n");
  	printf("My %d\n", ft_printf("%u\n", 1));                        //   -> "1"
 	printf("Or %d\n", 	 printf("%u\n", 1));
 	printf("<------>\n");
  	printf("My %d\n", ft_printf("%u\n", -1));                      //    -> "4294967295"
 	printf("Or %d\n", 	 printf("%u\n", -1)); 
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%u\n", 4294967295));              //    -> "4294967295"
 	printf("Or %d\n", 	 printf("%u\n", 4294967295));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%u\n", 4294967296));              //    -> "0"
 	printf("Or %d\n", 	 printf("%u\n", 4294967296));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%5u\n", 4294967295));             //    -> "4294967295"
 	printf("Or %d\n", 	 printf("%5u\n", 4294967295));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%15u\n", 4294967295));            //    -> "     4294967295"
 	printf("Or %d\n", 	 printf("%15u\n", 4294967295));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%015u\n", 4294967295));           //    -> "000004294967295"
 	printf("Or %d\n", 	 printf("%015u\n", 4294967295));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("% u\n", 4294967295));             //    -> "4294967295"
 	printf("Or %d\n", 	 printf("% u\n", 4294967295));
	printf("<------>\n");
 	printf("My %d\n", ft_printf("%+u\n", 4294967295));             //    -> "4294967295"
	printf("Or %d\n", 	 printf("%+u\n", 4294967295));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%lu\n", 4294967295));             //    -> "4294967295"
 	printf("Or %d\n", 	 printf("%lu\n", 4294967295)); 
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%lu\n", 4294967296));              //   -> "4294967296"
 	printf("Or %d\n", 	 printf("%lu\n", 4294967296));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%lu\n", -42));                    //    -> "18446744073709551574"
 	printf("Or %d\n", 	 printf("%lu\n", -42));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%llu\n", 4999999999));             //   -> "4999999999"
 	printf("Or %d\n", 	 printf("%llu\n", 4999999999));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%ju\n", 4999999999));              //   -> "4999999999"
 	printf("Or %d\n", 	 printf("%ju\n", 4999999999));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%ju\n", 4294967296));              //   -> "4294967296"
 	printf("Or %d\n", 	 printf("%ju\n", 4294967296));
 	printf("<------>\n");
 	*/
 	/*
	printf("Testing specifier %o\n");	
	printf("My %d\n", ft_printf("%-5.10o\n", 2500));                  // -> "0000004704"
  	printf("Or %d\n", 	 printf("%-5.10o\n", 2500));
  	printf("<------>\n");
  	printf("My %d\n", ft_printf("%-10.5o\n", 2500));                  // -> "04704     "
  	printf("Or %d\n", 	 printf("%-10.5o\n", 2500));
  	printf("<------>\n");
  	printf("My %d\n", ft_printf("@moulitest: %.o %.0o\n", 0, 0));     // -> "@moulitest:  "
  	printf("Or %d\n", 	 printf("@moulitest: %.o %.0o\n", 0, 0));
  	printf("<------>\n");
   	printf("My %d\n", ft_printf("@moulitest: %5.o %5.0o\n", 0, 0));   // -> "@moulitest:            "
  	printf("Or %d\n", 	 printf("@moulitest: %5.o %5.0o\n", 0, 0));
  	printf("<------>\n");
   	printf("My %d\n", ft_printf("@moulitest: %#.o %#.0o\n", 0, 0));   // -> "@moulitest: 0 0"
	printf("Or %d\n", 	 printf("@moulitest: %#.o %#.0o\n", 0, 0));
	printf("<------>\n");
	printf("My %d\n", ft_printf("@moulitest: %5.x %5.0x", 0, 0)); // -> "@moulitest:            "
	printf("Or %d\n", 	 printf("@moulitest: %5.x %5.0x", 0, 0));
	printf("<------>\n");
	printf("My %d\n", ft_printf("% o|%+o\n", 42, 42));
 	printf("Or %d\n", 	 printf("% o|%+o\n", 42, 42));
 	printf("<------>\n");
	printf("My %d\n", ft_printf("%#o\n", 0));
 	printf("Or %d\n", 	 printf("%#o\n", 0));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%+o\n", 0));
 	printf("Or %d\n", 	 printf("%+o\n", 0));
 	printf("<------>\n");
	printf("My %d\n", ft_printf("%-5.10o", 2500)); // -> "0000004704"
	printf("Or %d\n", 	 printf("%-5.10o", 2500));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-10.5o", 2500)); // -> "04704     "
	printf("Or %d\n", 	 printf("%-10.5o", 2500));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%5o", 41));  //    -> "   51"
  	printf("Or %d\n", 	 printf("%5o", 41)); 
  	printf("<------>\n");
  	printf("My %d\n", ft_printf("%-5o", 2500));   //    -> "4704 "
  	printf("Or %d\n", 	 printf("%-5o", 2500));
  	printf("<------>\n");
  	printf("My %d\n", ft_printf("%#6o", 2500));//    -> " 04704"
	printf("Or %d\n", 	 printf("%#6o", 2500));
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-#6o", 2500)); //     -> "04704 "
	printf("Or %d\n", 	 printf("%-#6o", 2500)); 
	printf("<------>\n");
	printf("My %d\n", ft_printf("%-05o", 2500)); //    -> "4704 "
	printf("Or %d\n", 	 printf("%-05o", 2500)); 
	printf("<------>\n");
	*/
 	
 	printf("unexpected behavior\n");
  	ft_printf("%|\n");                          //     -> ""
  	printf("%|\n");
  	printf("<------>\n");
  	ft_printf("% |\n");                         //     -> ""
   	printf("% |\n");
   	printf("<------>\n");
   	ft_printf("% h|\n");                        //     -> ""
   	printf("% h|\n");
   	printf("<------>\n");
   	ft_printf("%Z|\n");                         //     -> "Z"
   	printf("%Z|\n"); 
   	printf("<------>\n");
   	ft_printf("% hZ|\n");                       //     -> "Z"
   	printf("% hZ|\n");
   	printf("<------>\n");
   	ft_printf("% hZ%|\n");                      //     -> "Z"
    printf("% hZ%|\n");
    printf("<------>\n");
    ft_printf("% Z|\n", "test");                //     -> "Z"
   	printf("% Z|\n", "test");
   	printf("<------>\n");
   	ft_printf("% Z |\n", "test");               //     -> "Z "
   	printf("% Z |\n", "test");
   	printf("<------>\n");
   	ft_printf("% Z%s|\n", "test");              //     -> "Ztest"
  	printf("% Z%s|\n", "test");
  	printf("<------>\n");
  	ft_printf("%000   %|\n", "test");           //     -> "%"
   	printf("%000   %|\n", "test");
   	printf("<------>\n");
   	ft_printf("%%%|\n", "test");                //     -> "%"
  	printf("%%%|\n", "test");
  	printf("<------>\n");
  	ft_printf("%%   %|\n", "test");             //     -> "%   "
   	printf("%%   %|\n", "test");
   	printf("<------>\n");
   	ft_printf("% Z|\n", 42);                    //     -> "Z"
  	printf("% Z|\n", 42); 
  	printf("<------>\n");
  	ft_printf("%0 d|\n", 42);                   //     -> " 42"
   	printf("%0 d|\n", 42);
   	printf("<------>\n");
   	ft_printf("%5+d|\n", 42);                   //     -> "  +42"
   	printf("%5+d|\n", 42);
   	printf("<------>\n");
   	ft_printf("%-5+d|\n", 42);                  //     -> "+42  "
   	printf("%-5+d|\n", 42);
   	printf("<------>\n");
   	ft_printf("%lhl|\n", 9223372036854775807);  //     -> ""
   	printf("%lhl|\n", 9223372036854775807);
   	printf("<------>\n");
   	ft_printf("%lhlz|\n", 9223372036854775807); //     -> ""
 	printf("%lhlz|\n", 9223372036854775807);
 	printf("<------>\n");
 	ft_printf("%zj|\n", 9223372036854775807);   //     -> ""
  	printf("%zj|\n", 9223372036854775807); 
  	printf("<------>\n");
  	ft_printf("%lhh|\n", 2147483647);           //     -> ""
   	printf("%lhh|\n", 2147483647); 
   	printf("<------>\n");
   	ft_printf("%hhld|\n", 128);                 //     -> "128"
 	printf("%hhld|\n", 128);
 	printf("<------>\n");
 	ft_printf("@main_ftprintf: %####0000 33..1..#00d|\n", 256);// -> "@main_ftprintf:                               256$\n"
  	printf("@main_ftprintf: %####0000 33..1..#00d|\n", 256);
  	printf("<------>\n");
  	ft_printf("@main_ftprintf: %####0000 33..1d|\n", 256);// -> "@main_ftprintf:                               256"
	printf("@main_ftprintf: %####0000 33..1d|\n", 256);
	printf("<------>\n");
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d|\n", 256);// -> "@main_ftprintf: +256   
	printf("@main_ftprintf: %###-#0000 33...12..#0+0d|\n", 256);
	printf("<------>\n");
/*
 	int i = 345;
 	int test_simple_mix = 345;
 	printf("mulitest checked\n");

 	printf("My %d\n", ft_printf("%p\n", &i));
 	printf("Or %d\n", 	 printf("%p\n", &i));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%\n"));
 	printf("Or %d\n", 	 printf("%\n"));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42));
 	printf("Or %d\n", 	 printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%U\n", ULONG_MAX));
 	printf("Or %d\n", 	 printf("%U\n", ULONG_MAX));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%lu, %lu\n", 0, ULONG_MAX));
 	printf("Or %d\n", 	 printf("%lu, %lu\n", 0, ULONG_MAX));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%llu, %llu\n", 0, ULLONG_MAX));
 	printf("Or %d\n", 	 printf("%llu, %llu\n", 0, ULLONG_MAX));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%ju, %ju\n", 0, ULLONG_MAX));
 	printf("Or %d\n", 	 printf("%ju, %ju\n", 0, ULLONG_MAX));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%zu, %zu\n", 0, ULLONG_MAX));
 	printf("Or %d\n", 	 printf("%zu, %zu\n", 0, ULLONG_MAX));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%lp\n", 42));
 	printf("Or %d\n", 	 printf("%lp\n", 42));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%.0p, %.p\n", 0, 0));
 	printf("Or %d\n", 	 printf("%.0p, %.p\n", 0, 0));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("%.p, %.0p\n", 0, 0));
 	printf("Or %d\n", 	 printf("%.p, %.0p\n", 0, 0));
 	printf("<------>\n");
 	printf("My %d\n", ft_printf("% p|%+p\n", 42, 42));
 	printf("Or %d\n", 	 printf("% p|%+p\n", 42, 42));
 	printf("<------>\n");

*/
 	return (0);
	
}
