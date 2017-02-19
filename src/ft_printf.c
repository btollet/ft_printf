/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:48:37 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/19 20:49:36 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_data	data;
	va_list	ar;

	data = init();
	va_start(ar, str);
	return (check_str(data, str, ar));
}

t_data	init()
{
	t_data	data;

	data.i = 0;
	data.nb_char = 0;
	return (data);
}

int		check_str(t_data data, char *str, va_list ar)
{
	while (str[data.i])
	{
		if (str[data.i] == '%')
		{
			data.i++;
			
			if (str[data.i] == 's')
				s_ar(&data, va_arg(ar, char *));
			if (str[data.i] == 'd')
				d_ar(&data, va_arg(ar, int));
		}
		else
		{
			ft_putchar(str[data.i]);
			data.i++;
			data.nb_char++;
		}
	}
	return (data.nb_char);
}

void	s_ar(t_data *data, char *ar)
{
	if (ar)
	{
		ft_putstr(ar);
		data->nb_char += (ft_strlen(ar));
	}
	else
	{
		ft_putstr("(null)");
		data->nb_char += 6;
	}
	data->i++;
}

void	d_ar(t_data *data, int nb)
{
	char *str;

	str = ft_itoa(nb);
	ft_putstr(str);
	data->nb_char += (ft_strlen(str));
	data->i++;
}