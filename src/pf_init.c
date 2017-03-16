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
	data.no_reset = 0;
	return (data);
}

void	reset_option(t_data *data, char *str, int j, int all)
{
	if (all == 0 && data->no_reset == 0)
	{
		data->sharp = 0;
		data->plus = 0;
		data->less = 0;
		data->zero = 0;
		data->precision = 0;
		data->c_option = ' ';
		data->null = 0;
		data->prec_ok = 0;
		data->digit_found = 0;
	}
	str += data->i + j;
	data->no_reset = 0;
	get_option(data, str, 1, 0);
}

void	reset_result(t_data *data)
{
	if (data->nb_char > 0)
	{
		ft_putstr(data->result);
		ft_memdel((void *)&data->result);
		data->result = ft_strnew(0);
	}
}
