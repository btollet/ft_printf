/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:06:03 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/17 20:27:13 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_ar(t_data *data, long nb, int j)
{
	char	*str;
	char	*final;
	int		i;

	i = 0;
	str = ft_strnew(18);
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = data->hex[nb % 16];
		nb /= 16;
	}
	str[i] = 0;
	str = ft_revstr(str);
	if (data->c_option == '0' && data->option > 0 && data->precision < data->option)
	{
		data->result = ft_strappend(data->result, "0x");
		data->nb_char += 2;
		if (data->prec_ok == 0)
		data->option -= 2;
		final = ft_strdup(str);
	}
	else
		final = ft_strjoin("0x", str);
	if (data->null == 1)
	{
		data->result = ft_strappend(data->result, "0x");
		data->nb_char += 2;
	}
	res_join(data, final, 0);
	ft_memdel((void *)&str);
	ft_memdel((void *)&final);
	data->i += 1 + j;
}

void	d_maj_ar(t_data *data, void *ar, int j)
{
	long	nb;
	char 	*str;


	nb = (long)ar;
	str = ft_itoa_long(nb);

	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	o_ar(t_data *data, void *nb, int j)
{
	int				i;
	char			*str;
	unsigned int	deci;

	i = 0;
	deci = (unsigned int)nb;
	str = ft_strnew(17);
	str[0] = '0';
	while (deci != 0)
	{
		str[i] = (deci % 8) + 48;
		deci /= 8;
		i++;
	}
	if (data->sharp == 1)
		str[i] = '0';
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	o_maj_ar(t_data *data, void *nb, int j)
{
	int				i;
	char			*str;
	unsigned long	deci;

	i = 0;
	deci = (unsigned long)nb;
	str = ft_strnew(22);
	str[0] = '0';
	while (deci != 0)
	{
		str[i] = (deci % 8) + 48;
		deci /= 8;
		i++;
	}
	if (data->sharp == 1)
		str[i] = '0';
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}
