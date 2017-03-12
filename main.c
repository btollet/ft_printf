#include <stdio.h>
#include <locale.h>
#include "src/ft_printf.h"
#include <limits.h>



int	main()
{
	setlocale(LC_ALL, "");
	printf("     Result: %d\n", ft_printf("{%            -d   }", 42));
	printf("     Result: %d\n\n", printf("{%            -d   }", 42));

	printf("     Result: %d\n", ft_printf("{%-10d}", 42));
	printf("     Result: %d\n\n", printf("{%-10d}", 42));

	printf("     Result: %d\n", ft_printf("%-10.5d", 4242));
	printf("     Result: %d\n\n", printf("%-10.5d", 4242));

	printf("     Result: %d\n", ft_printf("@moulitest: %.d %.0d", 42, 43));
	printf("     Result: %d\n\n", printf("@moulitest: %.d %.0d", 42, 43));

	printf("     Result: %d\n", ft_printf("%ll#x", 9223372036854775807));
	printf("     Result: %d\n\n", printf("%ll#x", 9223372036854775807));

	printf("     Result: %d\n", ft_printf("%lld%lld", 0, 42));
	printf("     Result: %d\n\n", printf("%lld%lld", 0, 42));

	printf("     Result: %d\n", ft_printf("%zhd", "4294967296"));
	printf("     Result: %d\n\n", printf("%zhd", "4294967296"));

	printf("     Result: %d\n", ft_printf("%lhl", "9223372036854775807"));
	printf("     Result: %d\n\n", printf("%lhl", "9223372036854775807"));

	printf("     Result: %d\n", ft_printf("%hhld", "128"));
	printf("     Result: %d\n\n", printf("%hhld", "128"));

	printf("     Result: %d\n", ft_printf("%hld", "128"));
	printf("     Result: %d\n\n", printf("%hld", "128"));

	printf("     Result: %d\n", ft_printf("%hhd", "128"));
	printf("     Result: %d\n\n", printf("%hhd", "128"));

	printf("     Result: %d\n", ft_printf("%+010d is a string", 42));
	printf("     Result: %d\n\n", printf("%+010d is a string", 42));

	printf("     Result: %d\n", ft_printf("{%+03d}", 0));
	printf("     Result: %d\n\n", printf("{%+03d}", 0));

	printf("     Result: %d\n", ft_printf("%5+d", 42));
	printf("     Result: %d\n\n", printf("%5+d", 42));

	printf("     Result: %d\n", ft_printf("%-0+5d", 42));
	printf("     Result: %d\n\n", printf("%-0+5d", 42));

	printf("     Result: %d\n", ft_printf("%-+10.5d", 4242));
	printf("     Result: %d\n\n", printf("%-+10.5d", 4242));

	printf("     Result: %d\n", ft_printf("@main_ftprintf: %-33.d\n", 256));
	printf("     Result: %d\n\n", printf("@main_ftprintf: %-33.d\n", 256));

	printf("     Result: %d\n", ft_printf("@main_ftprintf: %##-##0000 33...12..#00d", 256));
	printf("     Result: %d\n\n", printf("@main_ftprintf: %##-##0000 33...12..#00d", 256));

	printf("     Result: %d\n", ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));
	printf("     Result: %d\n\n", printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));

	printf("     Result: %d\n", ft_printf("{%05.S}", L"42 c est cool"));
	printf("     Result: %d\n\n", printf("{%05.S}", L"42 c est cool"));

	printf("     Result: %d\n", ft_printf("%4.S", L"我是一只猫。"));
	printf("     Result: %d\n\n", printf("%4.S", L"我是一只猫。"));

	printf("     Result: %d\n", ft_printf("%hhC, %hhC", 0, L'米'));
	printf("     Result: %d\n\n", printf("%hhC, %hhC", 0, L'米'));

	printf("     Result: %d\n", ft_printf("%ll# --- h00012.3.5.28d\n", 42));
	printf("     Result: %d\n\n", printf("%ll# --- h00012.3.5.28d\n", 42));
	return (1);
}