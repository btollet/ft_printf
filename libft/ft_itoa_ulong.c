/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 21:11:03 by btollet           #+#    #+#             */
/*   Updated: 2017/02/26 21:11:04 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_ulong(unsigned long n)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_ulonglen(n);
	if ((result = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	result[len] = '\0';
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
