/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:42:53 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/17 20:57:28 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_ar(t_data *data, void *ar, int j, char x)
{
	char			*str;
	int				i;

	data->i += 1 + j;
	str = x_ar_convert(data, ar);
	i = ft_strlen(str);
	if (data->prec_ok && data->null == 2 && (unsigned int)ar == 0)
		return ;
	if (data->sharp == 1 && (unsigned int)ar != 0 && data->c_option == '0')
		x_ar_part2(data, x);
	else if (data->sharp == 1 && (unsigned int)ar != 0)
	{
		str[i++] = 'x';
		str[i++] = '0';
	}
	while (x == 'X' && --i >= 0)
		str[i] = ft_toupper(str[i]);
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
}

void	x_ar_part2(t_data *data, char x)
{
	if (x == 'x')
		data->result = ft_strappend(data->result, "0x");
	else
		data->result = ft_strappend(data->result, "0X");
	data->nb_char += 2;
	if (data->prec_ok == 0)
		data->option -= 2;
}

char	*x_ar_convert(t_data *data, void *ar)
{
	unsigned int	nb;
	char			*str;
	int				i;

	i = 0;
	str = ft_strnew(23);
	nb = (unsigned int)ar;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = data->hex[nb % 16];
		nb /= 16;
	}
	return (str);
}
