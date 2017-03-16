/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:17:38 by btollet           #+#    #+#             */
/*   Updated: 2017/03/16 17:17:41 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_option(t_data *data, char *str, int j, char last)
{
	if (last != 0)
		str += j;
	if (*str == '0' || *str == '.')
	{
		if (*str == '0')
			data->zero = 1;
		if (*str == '.' && data->option != 0)
		{
			if (((data->precision < data->option && data->option > 0)
				|| (data->precision > data->option && data->option < 0))
				&& data->prec_ok == 0)
				data->precision = data->option;
			data->option = 0;
		}
		if (*str == '0' && last == '.' && data->null == 0)
			data->null = 1;
		if (*str == '.')
			data->prec_ok = 1;
		data->c_option = '0';
		data->i++;
		get_option(data, str, 1, *str);
	}
	else
		get_option_part2(data, str, last);
}

void	get_option_part2(t_data *data, char *str, char last)
{
	if (*str == '#')
	{
		data->null = 2;
		data->sharp = 1;
		data->i++;
		get_option(data, str, 1, *str);
	}
	else if (ft_isdigit(*str) || *str == '-' || *str == '+')
		get_digit_option(data, str, last);
	else if (last == '.' && data->null == 0)
		data->null = 1;
	else if (last == 0)
		data->option = 0;
}

void	get_digit_option(t_data *data, char *str, char last)
{
	int		save;

	save = data->option;
	if ((data->option = ft_atoi(str)) < 0)
		data->c_option = ' ';
	if (*str == '+')
		data->plus = 1;
	if (*str == '-')
		data->less = 1;
	if (data->option == 0 && (*str == '-' || *str == '+')
		&& !ft_isdigit(str[1]))
	{
		if (save < 0)
			data->option = save;
		else
			data->precision = save;
	}
	get_digit_option_part2(data, str, last);
}

void	get_digit_option_part2(t_data *data, char *str, char last)
{
	int		len;

	if (data->plus == 1 && data->less == 1 && data->digit_found == 1
		&& (*str == '-' || *str == '+'))
	{
		if (data->option > 0)
			data->option--;
		else if (data->option < 0)
			data->option++;
	}
	if (((*str == '-' || *str == '+') && ft_isdigit(str[1]))
		|| ft_isdigit(*str))
		data->digit_found = 1;
	len = ft_atoilen(str);
	data->i += len;
	if (data->less == 1 && data->option > 0 && last != '.')
		data->option = -data->option;
	if (len <= 0)
		len = 1;
	get_option(data, str, len, *str);
}
