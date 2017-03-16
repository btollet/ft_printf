/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hh_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:55:18 by btollet           #+#    #+#             */
/*   Updated: 2017/03/16 16:55:20 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hhd_ar(t_data *data, void *ar, int j)
{
	char	*str;
	char	nb;

	nb = (char)ar;
	data->i += 1 + j;
	while (j-- && nb >= 0)
		res_join(data, 0, ' ');
	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
}

void	hhu_ar(t_data *data, void *ar, int j)
{
	unsigned char	nb;
	char			*str;

	nb = (unsigned char)ar;
	str = ft_itoa_ulong(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	hho_ar(t_data *data, void *nb, int j)
{
	int				i;
	char			*str;
	unsigned char	deci;

	i = 0;
	deci = (unsigned int)nb;
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

void	hho_maj_ar(t_data *data, void *nb, int j)
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

void	hhx_ar(t_data *data, void *ar, int j, char x)
{
	unsigned char	nb;
	char			*hex;
	char			*str;
	int				i;

	i = 0;
	str = ft_strnew(21);
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	nb = (unsigned char)ar;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = 0;
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}
