/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:21:26 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/17 20:43:18 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_ar(t_data *data, void *ar, int j, char u)
{
	unsigned long	nb;
	char 			*str;

	if (u == 'u')
		nb = (unsigned int)ar;
	else
		nb = (unsigned long)ar;
	str = ft_itoa_ulong(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	c_maj_ar(t_data *data, void *ar, int j)
{
	wchar_t	tmp;

	tmp = (wchar_t)ar;
	if (tmp <= 0x7f)
		c_ar(data, (int)ar, j);
	else
	{
		reset_result(data);
		if (tmp <= 0x7ff)
			s_maj_write(data, tmp, 2, 0);
		else if (tmp <= 0xffff)
			s_maj_write(data, tmp, 3, 0);
		data->i += 1 + j;
	}
}

void	diese_ar(t_data *data, int j)
{
	if (data->prec_ok == 1)
		data->option = 0;
	if (data->null > 0)
		data->null = 0;
	if (data->precision)
	{
		space(data, data->precision - 1);
		data->precision = 0;
	}
	res_join(data, NULL, '%');
	data->i += 1 + j;
}
