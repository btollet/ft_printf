/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:37:04 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/19 22:09:01 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	char	*result;
	char	*cpy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if ((result = ft_strnew(len)) == NULL)
		return (NULL);
	cpy = result;
	while (--len >= 0)
		*result++ = str[len];
	*result = 0;
	return (cpy);
}