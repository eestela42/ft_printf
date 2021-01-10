#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"


int main()
{
	
	void	*a;
	int		r;
	int		t;
	char	bar;

	bar = 124;
	a = malloc(sizeof(int));
	//write(1,  &bar, 1);
	r = ft_printf("|%p|\n", NULL);
	//printf("|\n|");
	t =    printf("|%p|\n", NULL);
	//printf("t = %i\n", t - 3);
	printf("r = %i\nt = %i\n", r - 3, t - 3);
	
	
/*
	printf("rien=	|%s|\n", "miaou mieou");
	printf("plus=	|%+s|\n", "miaou mieou");
	printf("minus=	|%-s|\n", "miaou mieou");
	printf("zero=	|%0s|\n", "miaou mieou");
	printf("Width=	|%20s|\n", "miaou mieou");
	printf("preci=	|%.20s|\n", "miaou mieou");
*/
/*
	int r;
	char *tab;
	//int v;

	tab = "abcdef";
	r = printf("\n|%c|\n", tab[2]);
	//v = printf("\n|%10x|\n", 42);
	printf("r = %i\n", r);
	*/
}