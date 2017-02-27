#include <stdio.h>
#include <locale.h>
#include "src/ft_printf.h"
#include <limits.h>


int	main()
{
	int result;
	char i;
	char c;
	
setlocale(LC_ALL, "");
	i = 'a';
	ft_putendl("Moi:");
	result = ft_printf("%s\n%d\n%p\n%%\n%S\n%D\n%i\n%o\n%O\n->%u\n%U\n%x\n%X\n%c\n%C\n\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	result = ft_printf("->%u\n",100000);
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	ft_putendl("Printf:");
	result = printf("%s\n%d\n%p\n%%\n%S\n%D\n%i\n%o\n%O\n->%u\n%U\n%x\n%X\n%c\n%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	/*ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");*/
	return (1);
}