#include <stdio.h>
#include "ft_printf.h"


int	main(void)
{
	int exp;
	int	res;
	//int a = 5;
	//char	str[10] = "hello";
	
	/*exp = printf("|%.p|\n", NULL);
	res = ft_printf("|%.p|\n", NULL);
	printf("exp = %d\n", exp);
	printf("res = %d\n\n", res);*/
	exp = printf("original |%*d|\n", -2147483648, 1);
	res = ft_printf("my print|%*d|\n", -2147483648, 1);
	printf("exp = %d\n", exp);
	printf("res = %d\n\n", res);
	/*exp = printf("|%5p|\n", 0);
	res = ft_printf("|%5p|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n\n", res);*/
}







/*int	main(void)
{
	int		a = -2147483648; //без минуса, но в записи идет сминусом
	char	d = 'd';
	long	c = 34234234;
	int		*p;
	char	*p_d;
	long	*p_c;
	int		pf;
	int		ft;

	p = &a;
	pf = printf("original |%05d|\n", a);
	ft = ft_printf("& and my |%05d|\n", a);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
	pf = printf("original |%-d|\n", -42);
	ft = ft_printf("& and my |%-d|\n", -42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
	pf = printf("original |%-*d|\n", -42, -42);
	ft = ft_printf("& and my |%-*d|\n", -42, -42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
	pf = printf("original |%*d|\n", -42, -42);
	ft = ft_printf("& and my |%*d|\n", -42, -42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
	pf = printf("original |%-10.5d|\n", 100);
	ft = ft_printf("& and my |%-10.5d|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%010d|\n", 100);
	ft = ft_printf("& and my |%010d|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%10.5d|\n", 100);
	ft = ft_printf("& and my |%10.5d|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("Magic |%s| is |%-5d|\n", "number\n", -42);
	ft = ft_printf("Magic |%s| is |%-5d|\n", "number\n", -42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%-*c|     |%c|\n", 4, d, d);
	ft = ft_printf("& and my |%-*c|     |%c|\n", 4, d, d);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%*c|     |%c|\n", -4, d, d);
	ft = ft_printf("& and my |%*c|     |%c|\n", -4, d, d);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("|%*.3s|\n", -10, "toto");
	ft = ft_printf("|%*.3s|\n", -10, "toto");
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%-10.5X|\n", 100);
	ft = ft_printf("& and my |%-10.5X|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%010x|\n", 100);
	ft = ft_printf("& and my |%010x|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%10.5X|\n", 100);
	ft = ft_printf("& and my |%10.5X|\n", 100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%%|\n");
	ft = ft_printf("& and my |%%|\n");
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("Magic |%s| is |%5d|\n", "number\n", -42);
	ft = ft_printf("Magic |%s| is |%5d|\n", "number\n", -42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("Hexadecimal for %.5d is %x\n", -42, 42);
	ft = ft_printf("Hexadecimal for %.5d is %x\n", -42, 42);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("X = |%X|\n", 425452);
	ft = ft_printf("X = |%X|\n", 425452);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("|%.5i|\n", 4200);
	ft = ft_printf("|%.5i|\n", 4200);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("|%-15.12d|\n", a); // ошибка при работе с минусом
	ft = ft_printf("|%-15.12d|\n", a); // ошибка при работе с минусом
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("|%-15p|\n", p);
	ft = ft_printf("|%-15p|\n", p);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("|%15p|\n", p);
	ft = ft_printf("|%15p|\n", p);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	p_d = &d;
	pf = printf("|%p|\n", p_d);
	ft = ft_printf("|%p|\n", p_d);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	p_c = &c;
	pf = printf("|%p|\n", p_c);
	ft = ft_printf("|%p|\n", p_c);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf("original |%-10d|\n", -100);
	ft = ft_printf("& and my |%-10d|\n", -100);
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);	
	pf = printf( "|%0*x|\n", 8, 15 );
	ft = ft_printf( "|%0*x|\n", 8, 15 );
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
	pf = printf("|%05%|\n");
	ft = ft_printf("|%05%|\n");
	printf("original = %d\n", pf);
	printf("my funct = %d\n", ft);
		exp = printf("|%08.5u|\n", 34);
	res = ft_printf("|%08.5u|\n", 34);
	printf("exp = %d\n", exp);
	printf("res = %d\n\n", res);
	printf("|%5.0u|\n", a);
	ft_printf("|%5.0u|\n\n", a);
	exp = printf("|%08.5u|\n", 0);
	res = ft_printf("|%08.5u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%08.3u|\n", 8375);
	res = ft_printf("|%08.3u|\n", 8375);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%.0u|\n", 0);
	res = ft_printf("|%.0u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%.u|\n", 0);
	res = ft_printf("|%.u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%5.0u|\n", 0);
	res = ft_printf("|%5.0u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%5.u|\n", 0);
	res = ft_printf("|%5.u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%-5.0u|\n", 0);
	res = ft_printf("|%-5.0u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
	exp = printf("|%-5.u|\n", 0);
	res = ft_printf("|%-5.u|\n", 0);
	printf("exp = %d\n", exp);
	printf("res = %d\n", res);
}*/