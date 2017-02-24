/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:23:07 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/24 12:30:33 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		check_str(t_data data, char *str, va_list ar)
{
	while (str[data.i] && data.nb_char != -1)
	{
		if (str[data.i] == '%')
		{
			data.i++;
			check_arg(&data, str, ar, 0);
		}
		else
		{
			res_join(&data, NULL, str[data.i]);
			data.i++;
		}
	}
	return (data);
}

void	check_arg(t_data *data, char *str, va_list ar, int j)
{
	if (str[data->i + j] == 's')
		s_ar(data, va_arg(ar, char *), j);
	else if (str[data->i + j] == 'c')
		c_ar(data, va_arg(ar, int), j);
	else if (str[data->i + j] == 'd')
		d_ar(data, va_arg(ar, int), j);
	else if (str[data->i + j] == 'p')
		p_ar(data, va_arg(ar, long), j);
	else if (str[data->i + j] == 'S')
		s_maj_ar(data, va_arg(ar, long), j);
	else if (str[data->i + j] == '%')
	{
		res_join(data, NULL, '%');
		data->i += 1 + j;
	}
	else if (str[data->i + j] == ' ')
		check_arg(data, str, ar, j + 1);
	else if (j != 0)
		data->i++;
}