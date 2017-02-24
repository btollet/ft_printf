/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:20:31 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/24 12:32:28 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_ar(t_data *data, char *ar, int j)
{
	if (ar)
		res_join(data, ar, 0); 
	else
		res_join(data, "(null)", 0);
	data->i += 1 + j;
}

void	c_ar(t_data *data, int ar, int j)
{
	char	tmp;

	tmp = ar;
	if (tmp)
		res_join(data, 0, tmp); 
	else
		data->nb_char++;
	data->i += 1 + j;
}

void	d_ar(t_data *data, int nb, int j)
{
	char *str;

	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	p_ar(t_data *data, long nb, int j)
{
	char	*hex;
	char	*str;
	int		i;

	i = 0;
	hex = ft_strnew(16);
	str = ft_strnew(16);
	hex = "0123456789abcdef";
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = 0;
	str = ft_revstr(str);
	res_join(data, "0x", 0);
	res_join(data, str, 0);
	data->i += 1 + j;
}
#include <stdio.h>

void	s_maj_ar(t_data *data, long ar, int j)
{
	printf("Number: %ld\n", ar);
	data->i += 1 + j;
	data->nb_char += 2;
}
