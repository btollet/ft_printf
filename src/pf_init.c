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
	return (data);
}

void	get_option(t_data *data, char *str, int j)
{
	str += data->i + j;
	data->sharp = 0;
	data->plus = 0;
	data->c_option = ' ';
	
	if (*str == '0')
	{
		data->c_option = '0';
		str++;
		data->i++;
	}
	if (*str == '#')
	{
		data->sharp = 1;
		str++;
		data->i++;
	}
	if (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		data->option = ft_atoi(str);
		if (*str == '+')
			data->plus = 1;
		data->i += ft_intlen(data->option);
	}
	else
		data->option = 0;
}
