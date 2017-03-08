#include <stdio.h>
#include <locale.h>
#include "src/ft_printf.h"
#include <limits.h>


int	main()
{
	int result;
	
setlocale(LC_ALL, "");
	ft_putendl("Moi:");
	result = ft_printf("%-5.2s is a string", "this");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	ft_putendl("Printf:");
	result = printf("%-5.2s is a string", "this");
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	return (1);
}