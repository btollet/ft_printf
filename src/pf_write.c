/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 01:23:30 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/07 18:43:12 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	res_join(t_data *data, char *str, char c)
{
	char	*tmp;
	int		len;

	len = 1;
	if (str)
		len = ft_strlen(str);
	if (data->less == 2)
		data->precision--;
	ft_putnbr(data->precision);
	while ((data->precision > data->option && data->precision > len && data->precision > 0)
		|| (data->null == 1 && data->precision > 0))
	{
		data->result = ft_strappend(data->result, " ");
		data->precision--;
		data->nb_char++;
	}
	if (data->null == 1)
	{
		data->null = 0;
		return ;
	}
	space(data, data->option - len);
	if (str)
		data->result = ft_strappend(data->result, str);
	if (c)
	{
		tmp = ft_strnew(1);
		*tmp = c;
		data->result = ft_strappend(data->result, tmp);
		ft_memdel((void *)&tmp);
	}
	data->nb_char += len;
	if (data->option + len < 0)
		space(data, -(data->option + len));
	data->option = 0;
}

void	space(t_data *data, int nb)
{
	char *str;

	if (data->plus == 2)
	{
		data->result = ft_strappend(data->result, "+");
		data->nb_char++;
		data->option--;
		nb--;
		data->plus = 0;
	}
	if (data->less == 2 && data->c_option == '0')
	{
		data->result = ft_strappend(data->result, "-");
		if (data->prec_ok == 0)
		{
			data->option--;
			nb--;
		}
		data->nb_char++;
		data->less = 0;
	}
	if (nb > 0)
	{
		data->nb_char += nb;
		str = ft_strnew(nb);
		while (--nb >= 0)
			str[nb] = data->c_option;
		data->result = ft_strappend(data->result, str);
		ft_memdel((void *)&str);
		data->option = 0;
	}
}
