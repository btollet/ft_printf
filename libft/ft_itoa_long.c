/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:05:30 by btollet           #+#    #+#             */
/*   Updated: 2017/02/26 18:05:33 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_long(long n)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_longlen(n);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n < -9223372036854775807)
		return (ft_strcpy(result, "-9223372036854775808"));
	result[len] = '\0';
	if (n < 0)
	{
		result[i] = '-';
		n = -n;
	}
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (result);
}
