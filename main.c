#include <stdio.h>
#include <locale.h>
#include "src/ft_printf.h"
#include <limits.h>


int	main()
{
	int result;
	
setlocale(LC_ALL, "");
	ft_putendl("Moi:");
	result = ft_printf("%.4S", L"我是一只猫。");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	ft_putendl("Printf:");
	result = printf("%.4S", L"我是一只猫。");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	return (1);
}