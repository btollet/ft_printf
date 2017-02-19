#include <stdio.h>

#include "src/ft_printf.h"

int	main()
{
	int result;

	ft_putendl("Moi:");
	result = ft_printf("%d", INT_MIN);
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	ft_putendl("Printf:");
	result = printf("%d", INT_MIN);
	ft_putendl("");
	ft_putnbr(result);
	ft_putendl("");
	return (1);
}