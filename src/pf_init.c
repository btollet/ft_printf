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

t_data	init(void)
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

void	reset_option(t_data *data, char *str, int j, int all)
{
	if (all == 0)
	{
		data->sharp = 0;
		data->plus = 0;
		data->less = 0;	
		data->precision = 0;
		data->c_option = ' ';
		data->null = 0;
		data->prec_ok = 0;	
	}
	str += data->i + j;
	get_option(data, str, 1, 0);
}

void	get_option(t_data *data, char *str, int j, char last)
{
	int		len;
	int		save;

	len = 1;
	if (last != 0)
		str += j;
	if (*str == '0' || *str == '.')
	{
		if (*str == '.')
			data->prec_ok = 1;
		if (*str == '.' && data->option != 0)
		{
			data->precision = data->option;
			data->option = 0;	
		}
		if (*str == '0' && last == '.' && data->null == 0) 
			data->null = 1;
		data->c_option = '0';
		data->i++;
		get_option(data, str, 1, *str);
	}
	else if (*str == '#')
	{
		data->null = 2;
		data->sharp = 1;
		data->i++;
		get_option(data, str, 1, *str);
	}
	else if (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		save = data->option;
		if ((data->option = ft_atoi(str)) < 0)
			data->c_option = ' ';
		if (*str == '+')
			data->plus = 1;
		if (*str == '-')
			data->less = 1;
		if (data->option == 0 && (*str == '-' || *str == '+') && !ft_isdigit(str[1]))
			data->option = save;
		len = ft_atoilen(str);
		data->i += len;
		if (data->less == 1 && data->option > 0 && last != '.')
			data->option = -data->option;
		if (len <= 0)
			len = 1;
		get_option(data, str, len, *str);
	}
	else if (last == '.' && data->null == 0)
		data->null = 1;
	else if (last == 0)
		data->option = 0;
}
