/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:23:07 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/04 00:37:41 by benjamin         ###   ########.fr       */
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
	get_option(data, str);
	if (str[data->i + j] == 's')
		s_ar(data, va_arg(ar, char *), j);
	else if (str[data->i + j] == 'c')
		c_ar(data, va_arg(ar, int), j);
	else if (str[data->i + j] == 'd' || str[data->i + j] == 'i')
		d_ar(data, va_arg(ar, int), j);
	else if (str[data->i + j] == 'p')
		p_ar(data, va_arg(ar, long), j);
	else if (str[data->i + j] == 'S')
		s_maj_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'D')
		d_maj_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'o')
		o_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'O')
		o_maj_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'U')
		u_maj_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'x' || str[data->i + j] == 'X')
		x_ar(data, va_arg(ar, void *), j, str[data->i + j]);
	else if (str[data->i + j] == 'C')
		c_maj_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == 'u')
		u_ar(data, va_arg(ar, void *), j);
	else if (str[data->i + j] == '%')
	{
		res_join(data, NULL, '%');
		data->i += 1 + j;
	}
	else if (str[data->i + j] == ' ')
		check_arg(data, str, ar, j + 1);
	else if (str[data->i + j] == 'l' || str[data->i + j] == 'z' || str[data->i + j] == 'j')
		check_l_arg(data, str, ar);
	else if (str[data->i + j] == 'h')
		check_h_arg(data, str, ar);
	else if (j != 0)
		data->i++;
}

void	check_l_arg(t_data *data, char *str, va_list ar)
{
	data->i++;
	if (str[data->i] == 's')
		s_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'c')
		c_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'd' || str[data->i] == 'i')
		d_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'S')
		s_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'D' || str[data->i] == 'u')
		u_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'o' || str[data->i] == 'O')
		lo_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'U')
		u_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'x' || str[data->i] == 'X')
		lx_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'C')
		c_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'l')
		check_l_arg(data, str, ar);
	else if (str[data->i] == 'p')
		p_ar(data, va_arg(ar, long), 0);
}

void	check_h_arg(t_data *data, char *str, va_list ar)
{
	data->i++;
	if (str[data->i] == 's')
		s_ar(data, va_arg(ar, char *), 0);
	else if (str[data->i] == 'c')
		c_ar(data, va_arg(ar, int), 0);
	else if (str[data->i] == 'd' || str[data->i] == 'i')
		d_ar(data, va_arg(ar, int), 0);
	else if (str[data->i] == 'p')
		p_ar(data, va_arg(ar, long), 0);
	else if (str[data->i] == 'S')
		s_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'D' || str[data->i] == 'u')
		d_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'o' || str[data->i] == 'O')
		o_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'U')
		u_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'x' || str[data->i] == 'X')
		x_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'C')
		c_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'h')
		check_hh_arg(data, str, ar);
}

void	check_hh_arg(t_data *data, char *str, va_list ar)
{
	data->i++;
	if (str[data->i] == 's')
		s_ar(data, va_arg(ar, char *), 0);
	else if (str[data->i] == 'c')
		c_ar(data, va_arg(ar, int), 0);
	else if (str[data->i] == 'd' || str[data->i] == 'i')
		hhd_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'p')
		p_ar(data, va_arg(ar, long), 0);
	else if (str[data->i] == 'S')
		s_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'D')
		d_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'u')
		hhu_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'o')
		hho_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'O')
		hho_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'U')
		u_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'x' || str[data->i] == 'X')
		hhx_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'C')
		c_maj_ar(data, va_arg(ar, void *), 0);
}
