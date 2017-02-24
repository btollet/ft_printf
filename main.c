#include <stdio.h>
#include <locale.h>
#include "src/ft_printf.h"



int	main()
{
	int result;
	char i;
	
setlocale(LC_ALL, "");
	i = 'a';
	ft_putendl("Moi:");
	result = ft_printf("%S", L"米");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	ft_putendl("Printf:");
	result = printf("%S", L"米");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	return (1);
}