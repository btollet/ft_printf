/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:29:16 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/04 00:08:15 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_h_arg(t_data *data, char *str, va_list ar)
{
	data->i++;
	if (str[data->i] == 's')
		s_ar(data, va_arg(ar, char *), 0);
	else if (str[data->i] == 'c')
		c_ar(data, va_arg(ar, int), 0);
	else if (str[data->i] == 'd' || str[data->i] == 'i')
		d_ar(data, va_arg(ar, void *), 0, 1);
	else if (str[data->i] == 'p')
		p_ar(data, va_arg(ar, long), 0);
	else if (str[data->i] == 'S')
		s_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'D' || str[data->i] == 'u')
		d_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'o' || str[data->i] == 'O')
		ho_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'U')
		u_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'x' || str[data->i] == 'X')
		x_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'C')
		c_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'h')
		check_hh_arg(data, str, ar);
	else if (str[data->i] == 'l' || str[data->i] == 'z' || str[data->i] == 'j')
		check_l_arg(data, str, ar, 0);
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
	else
		check_hh_arg_part2(data, str, ar);
}

void	check_hh_arg_part2(t_data *data, char *str, va_list ar)
{
	if (str[data->i] == 'o')
		hho_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'O')
		hho_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'U')
		u_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'x' || str[data->i] == 'X')
		hhx_ar(data, va_arg(ar, void *), 0, str[data->i]);
	else if (str[data->i] == 'C')
		c_maj_ar(data, va_arg(ar, void *), 0);
	else if (str[data->i] == 'h')
		check_hh_arg(data, str, ar);
	else if (str[data->i] == 'l' || str[data->i] == 'z' || str[data->i] == 'j')
		check_l_arg(data, str, ar, 0);
}

void	ho_ar(t_data *data, void *nb, int j)
{
	int				i;
	char			*str;
	unsigned short	deci;

	i = 0;
	deci = (unsigned short)nb;
	str = ft_strnew(16);
	str[0] = '0';
	while (deci != 0)
	{
		str[i] = (deci % 8) + 48;
		deci /= 8;
		i++;
	}
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}
