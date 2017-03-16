/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_l_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:31:28 by btollet           #+#    #+#             */
/*   Updated: 2017/03/16 16:31:30 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_l_arg(t_data *data, char *str, va_list ar, int j)
{
	data->i++;
	reset_option(data, str, j, 1);
	if (str[IJ] == 's')
		s_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'c')
		c_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'd' || str[IJ] == 'i')
		d_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'S')
		s_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'D' || str[IJ] == 'u' || str[IJ] == 'U')
		u_ar(data, va_arg(ar, void *), j, 'U');
	else if (str[IJ] == 'o' || str[IJ] == 'O')
		lo_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'x' || str[IJ] == 'X')
		lx_ar(data, va_arg(ar, void *), j, str[IJ]);
	else if (str[IJ] == 'C')
		c_maj_ar(data, va_arg(ar, void *), j);
	else if (str[IJ] == 'p')
		p_ar(data, va_arg(ar, long), j);
	else
		check_l_arg_pat2(data, str, ar, j);
}

void	check_l_arg_pat2(t_data *data, char *str, va_list ar, int j)
{
	if (str[IJ] == 'l' || str[IJ] == 'z'
		|| str[IJ] == 'j' || str[IJ] == 'h')
		check_l_arg(data, str, ar, 0);
	else if (str[IJ])
		check_l_arg(data, str, ar, j + 1);
}

void	lo_ar(t_data *data, void *nb, int j)
{
	int				i;
	char			*str;
	unsigned long	deci;

	i = 0;
	deci = (unsigned long)nb;
	str = ft_strnew(50);
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

void	lx_ar(t_data *data, void *ar, int j, char x)
{
	unsigned long	nb;
	char			*str;
	int				i;

	i = 0;
	str = ft_strnew(23);
	nb = (unsigned long)ar;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = data->hex[nb % 16];
		nb /= 16;
	}
	if (data->sharp == 1 && (unsigned long)ar != 0)
	{
		str[i++] = 'x';
		str[i++] = '0';
	}
	while (x == 'X' && --i >= 0)
		str[i] = ft_toupper(str[i]);
	str = ft_revstr(str);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}
