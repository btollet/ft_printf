/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:20:31 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/17 20:20:50 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_ar(t_data *data, char *ar, int j)
{
	char *cpy;

	if (ar)
	{
		if (data->prec_ok == 1 && data->option > 0)
		{
			cpy = ft_strnew(data->option);
			cpy = ft_strncpy(cpy, ar, data->option);
			data->option = 0;
			res_join(data, cpy, 0);
			ft_memdel((void *)&cpy);
		}
		else
			res_join(data, ar, 0); 
	}
	else if (data->precision)
	{
		data->null = 0;
		space(data, data->precision);
	}
	else
		res_join(data, "(null)", 0);
	data->i += 1 + j;
}

void	c_ar(t_data *data, int ar, int j)
{
	char	tmp;

	tmp = ar;
	if (tmp)
	{
		if (data->prec_ok == 1)
			data->option = 0;
		res_join(data, 0, tmp);
	}
	else if (j > 0)
	{
		reset_result(data);
		write_only(data, '\0');
	}
	else if (data->option || data->precision)
		c_ar_part2(data);
	else
		data->nb_char++;
	data->i += 1 + j;
}

void	c_ar_part2(t_data *data)
{
	data->option--;
	if (data->precision)
	{
		data->null = 0;
		space(data, data->precision - 1);
	}
	if (data->prec_ok == 0)
		res_join(data, 0, data->c_option);
	reset_result(data);
	write_only(data, '\0');
}

void	d_ar(t_data *data, void *ar, int j, int h)
{
	int		nb;

	if (h == 0)
		nb = (int)ar;
	else
		nb = (short)ar;
	data->i += 1 + j;
	if (data->plus == 1 && nb >= 0)
		data->plus = 2;
	while (j-- && nb >= 0 && data->plus == 0 && data->less == 0 && data->precision == 0)
	{
		data->result = ft_strappend(data->result, " ");
		data->option--;
		data->nb_char++;
	}
	d_ar_part2(data, nb);
}

void	d_ar_part2(t_data *data, int nb)
{
	char	*str;

	if (nb < 0 && data->c_option == '0' && data->option > 0)
	{
		nb = -nb;
		data->less = 2;
	}
	else if (data->less == 1)
	{
		if (nb < 0 && data->plus == 1)
			data->option--;
		data->less = 3;
	}
	if (data->null != 0 && nb != 0)
		data->null = 0;
	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
}
