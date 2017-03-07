/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:19:02 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/07 19:35:21 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init()
{
	t_data	data;

	data.result = ft_strnew(0);
	data.hex = "0123456789abcdef";
	data.i = 0;
	data.nb_char = 0;
	data.option = 0;
	data.precision = 0;
	return (data);
}

void	reset_option(t_data *data, char *str, int j)
{
	str += data->i + j;
	data->sharp = 0;
	data->plus = 0;
	data->less = 0;
	data->precision = 0;
	data->c_option = ' ';
	data->null = 0;
	data->prec_ok = 0;
	get_option(data, str, 1, 0);
}

void	get_option(t_data *data, char *str, int j, char last)
{
	if (last != 0)
		str += j;
	if (*str == '0' || *str == '.')
	{
		if (*str == '.')
			data->prec_ok = 1;
		if (*str == '.' && data->option > 0)
		{
			data->precision = data->option;
			data->option = 0;
			
		}
		if (*str == '0' && last == '.')
			data->null = 1;
		data->c_option = '0';
		data->i++;
		get_option(data, str, 1, *str);
	}
	else if (*str == '#')
	{
		data->sharp = 1;
		data->i++;
		get_option(data, str, 1, *str);
	}
	else if (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		if ((data->option = ft_atoi(str)) < 0)
			data->c_option = ' ';
		if (*str == '+')
			data->plus = 1;
		if (*str == '-')
			data->less = 1;
		data->i += ft_intlen(data->option);
		get_option(data, str, ft_intlen(data->option), *str);
	}
	else if (last == '.')
		data->null = 1;
	else if (last == 0)
		data->option = 0;
}
