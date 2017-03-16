/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:23:07 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/07 17:36:26 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_str(t_data data, char *str, va_list ar)
{
	while (str[data.i] && data.nb_char != -1)
	{
		data.precision = 0;
		data.null = 0;
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
	reset_option(data, str, j, 0);
	while (str[IJ] == ' ' && (data->plus == 1 || data->less == 1))
		j++;
	if (str[IJ] == 's')
		s_ar(data, va_arg(ar, char *), j);
	else if (str[IJ] == 'c')
		c_ar(data, va_arg(ar, int), j);
	else if (str[IJ] == 'd' || str[IJ] == 'i')
		d_ar(data, va_arg(ar, void *), j, 0);
	else if (str[IJ] == 'p')
		p_ar(data, va_arg(ar, long), j);
	else if (str[IJ] == 'S')
		s_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'D')
		d_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'o')
		o_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'O')
		o_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'u' || str[IJ] == 'U')
		u_ar(data, va_arg(ar, void *), j, str[IJ]);
	else if (str[IJ] == 'x' || str[IJ] == 'X')
		x_ar(data, va_arg(ar, void *), j, str[IJ]);
	else
		check_arg_part2(data, str, ar, j);
}

void	check_arg_part2(t_data *data, char *str, va_list ar, int j)
{
	if (str[IJ] == 'C')
		c_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == '%')
		diese_ar(data, j);
	else if (str[IJ] == ' ')
		check_arg(data, str, ar, j + 1);
	else if (str[IJ] == 'l' || str[IJ] == 'z' || str[IJ] == 'j')
		check_l_arg(data, str, ar, j);
	else if (str[IJ] == 'h')
		check_h_arg(data, str, ar);
	else if (data->precision)
	{
		space(data, data->precision - 1);
		if (j != 0)
			data->i++;
	}
	else if (ft_isprintfflag(str[IJ]))
	{
		data->no_reset = 1;
		check_arg(data, str, ar, j);
	}
	else if (j != 0)
		data->i++;
}
