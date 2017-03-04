/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:19:02 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/04 01:23:03 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init()
{
	t_data	data;

	data.result = ft_strnew(0);
	data.i = 0;
	data.nb_char = 0;
	data.option = 0;
	return (data);
}

void	get_option(t_data *data, char *str)
{
	str += data->i;
	if (ft_isdigit(*str) || *str == '-' || *str == '+')
	{
		data->option = ft_atoi(str);
		data->i += ft_intlen(data->option);
	}
	else
		data->option = 0;
}
