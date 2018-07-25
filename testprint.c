#include <stdio.h>
#include "./include/ft_printf.h"
#include <stdlib.h>

int main()
{
	char *arr = "Hello My da";// test arrays
	char c = 'H'; //test char symbols
	int i = 235315532;
	float f = 234.432;
	double d = 234.534;
	long l = 123234215;

	ft_printf("%#x\n", 42);                    //     -> "0x2a"
	ft_printf("%#llx\n", 9223372036854775807); //     -> "0x7fffffffffffffff"
	ft_printf("%#x\n", 42);                    //     -> "0x2a"
	ft_printf("%#X\n", 42);                    //     -> "0X2A"
	ft_printf("%#8x\n", 42);                   //     -> "    0x2a"
 	ft_printf("%#08x\n", 42);                  //     -> "0x00002a"
  	ft_printf("%#-08x\n", 42);                 //     -> "0x2a    "
 	ft_printf("%.2s is a string\n", "this");   //     -> "th is a string"
	ft_printf("%5.2s is a string\n", "this");  //     -> "   th is a string"
  	ft_printf("%-.2s is a string\n", "this");  //     -> "th is a string"
	ft_printf("%-5.2s is a string\n", "this"); //     -> "th    is a string"
	ft_printf("%-5.10o\n", 2500);              //     -> "0000004704"
	ft_printf("%-10.5o\n", 2500);              //     -> "04704     "
 	ft_printf("@moulitest: %.10o\n", 42);      //     -> "@moulitest: 0000000052"
	ft_printf("%4.15d\n", 42);                 //     -> "000000000000042"
	ft_printf("%.10d\n", 4242);                //     -> "0000004242"
	ft_printf("%10.5d\n", 4242);               //     -> "     04242"
	ft_printf("%-10.5d\n", 4242);              //     -> "04242     "
	ft_printf("% 10.5d\n", 4242);              //     -> "     04242"
	ft_printf("%+10.5d\n", 4242);              //     -> "    +04242"
	ft_printf("%-+10.5d\n", 4242);             //     -> "+04242    "
	ft_printf("%03.2d\n", 0);                  //     -> " 00"
	ft_printf("%03.2d\n", 1);                  //     -> " 01"
	ft_printf("%03.2d <> ", -1);               //     -> "-01"
	printf("%3.2d\n", -1);
	ft_printf("@moulitest: %.10d\n", -42);     //     -> "@moulitest: -0000000042"
	ft_printf("@moulitest: %.5u\n", 42);       //     -> "@moulitest: 00042"
	ft_printf("Characters: %c %c \n", 'a', 65); //   					Characters: a A
   	ft_printf("Decimals: %d %ld\n", 1977, 650000L);//					Decimals: 1977 650000
   	ft_printf("Preceding with blanks: %10d \n", 1977);//				Preceding with blanks:       1977
   	ft_printf("Preceding with zeros: %010d \n", 1977);//				Preceding with zeros: 0000001977
   	ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);// Some different radices: 100 64 144 0x64 0144
   	ft_printf("Width trick: %*d \n", 5, 10);			//				Width trick:    10
   	ft_printf("%s \n", "A string");						//				A string

	// printf("\tOriginal = |%s|", arr);
	// ft_printf("My printf = |%s|", arr);
	// printf("\n");

	// printf("\tOriginal = |%S|", arr);
	// ft_printf("My printf = |%S|", arr);
	// printf("\n");
	
	// printf("\tOriginal = |%c|", c);
	// ft_printf("My printf = |%c|", c);
	// printf("\n");
	
	// printf("\tOriginal = |%p|", c);
	// ft_printf("My printf = |%p|", c);
	// printf("\n");
	
	// printf("\tOriginal = |%lli|", i);
	// ft_printf("My printf = |%lli|", i);
	// printf("\n");

	// printf("\tOriginal = |%D|", i);
	// ft_printf("My printf = |%D|", i);
	// printf("\n");

	// printf("\tOriginal = |%d|", i);
	// ft_printf("My printf = |%d|", i);
	// printf("\n");

	// printf("\tOriginal = |%o|", i);
	// ft_printf("My printf = |%o|", i);
	// printf("\n");
	
	// printf("\tOriginal = |%O|", i);
	// ft_printf("My printf = |%O|", i);
	// printf("\n");

	// printf("\tOriginal = |%u|", i);
	// ft_printf("My printf = |%u|", i);
	// printf("\n");

	// printf("\tOriginal = |%U|", i);
	// ft_printf("My printf = |%U|", i);
	// printf("\n");

	// printf("\tOriginal = |%x|", i);
	// ft_printf("My printf = |%x|", i);
	// printf("\n");

	// printf("\tOriginal = |%X|", i);
	// ft_printf("My printf = |%X|", i);
	// printf("\n");

	// printf("\tOriginal = |%C|", i);
	// ft_printf("My printf = |%C|", i);
	// printf("\n");
	
	// printf("\tOriginal = |%%|");
	// ft_printf("My printf = |%%|");
	// printf("\n");

	// printf("\tOriginal = |%b|", 2354);
	// ft_printf("My printf = |%b|", 2354);
	// printf("\n");

	system("leaks exe");
	return (0);
}
