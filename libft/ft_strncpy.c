/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:00:32 by btollet           #+#    #+#             */
/*   Updated: 2017/02/13 23:06:32 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = dest;
	while (*src && i < n)
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		i++;
		dest++;
	}
	return (result);
}
