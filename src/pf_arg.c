/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:20:31 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/07 18:44:07 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diese_ar(t_data *data, int j)
{
	if (data->prec_ok == 1)
		data->option = 0;
	if (data->null > 0)
		data->null = 0;
	if (data->precision)
	{
		space(data, data->precision - 1);
		data->precision = 0;
	}
	res_join(data, NULL, '%');
	data->i += 1 + j;
}

void	s_ar(t_data *data, char *ar, int j)
{
	char *cpy;

	if (ar)
	{
		if (data->prec_ok == 1 && data->option > 0)
		{
			cpy = ft_strnew(data->option);
			cpy = ft_strncpy(cpy, ar, data->option);
			data->option = 0;
			res_join(data, cpy, 0);
			ft_memdel((void *)&cpy);
		}
		else
			res_join(data, ar, 0); 
	}
	else if (data->precision)
	{
		data->null = 0;
		space(data, data->precision);
	}
	else
		res_join(data, "(null)", 0);
	data->i += 1 + j;
}

void	c_ar(t_data *data, int ar, int j)
{
	char	tmp;

	tmp = ar;
	if (tmp)
	{
		if (data->prec_ok == 1)
			data->option = 0;
		res_join(data, 0, tmp);
	}
	else if (j > 0)
	{
		reset_result(data);
		write_only(data, '\0');
	}
	else if (data->option || data->precision)
	{
		data->option--;
		if (data->precision)
		{
			data->null = 0;
			space(data, data->precision - 1);
		}
		if (data->prec_ok == 0)
			res_join(data, 0, data->c_option);
		reset_result(data);
		write_only(data, '\0');
	}
	else
		data->nb_char++;
	data->i += 1 + j;
}

void	d_ar(t_data *data, void *ar, int j, int h)
{
	char	*str;
	int		nb;

	if (h == 0)
		nb = (int)ar;
	else
		nb = (short)ar;
	data->i += 1 + j;
	if (data->plus == 1 && nb >= 0)
		data->plus = 2;
	while (j-- && nb >= 0 && data->plus == 0 && data->less == 0 && data->precision == 0)
	{
		data->result = ft_strappend(data->result, " ");
		data->option--;
		data->nb_char++;
	}
	if (nb < 0 && data->c_option == '0' && data->option > 0)
	{
		nb = -nb;
		data->less = 2;
	}
	else if (data->less == 1)
	{
		if (nb < 0 && data->plus == 1)
			data->option--;
		data->less = 3;
	}
	if (data->null != 0 && nb != 0)
		data->null = 0;
	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
}

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

void	u_ar(t_data *data, void *ar, int j, char u)
{
	unsigned long	nb;
	char 			*str;

	if (u == 'u')
		nb = (unsigned int)ar;
	else
		nb = (unsigned long)ar;
	str = ft_itoa_ulong(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	x_ar(t_data *data, void *ar, int j, char x)
{
	unsigned int	nb; 
	char			*str;
	int				i;

	data->i += 1 + j;
	
	i = 0;
	str = ft_strnew(23);
	nb = (unsigned int)ar;
	if (data->prec_ok && data->null == 2 && nb == 0)
		return ;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = data->hex[nb % 16];
		nb /= 16;
	}
	if (data->sharp == 1 && (unsigned int)ar != 0 && data->c_option == '0')
	{
		if (x == 'x')
			data->result = ft_strappend(data->result, "0x");
		else
			data->result = ft_strappend(data->result, "0X");
		data->nb_char += 2;
		if (data->prec_ok == 0)
			data->option -= 2;
	}
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

void	c_maj_ar(t_data *data, void *ar, int j)
{
	wchar_t	tmp;
	char	c;

	tmp = (wchar_t)ar;
	if (tmp <= 0x7f)
		c_ar(data, (int)ar, j);
	else
	{
		reset_result(data);
		if (tmp <= 0x7ff)
		{
			c = (char) (0xc0 | (tmp >> 6));
			write (1, &c, 1);
			c = (char) (0x80 | (tmp & 0x3f));
			write (1, &c, 1);
			data->nb_char += 2;
		}
		else if (tmp <= 0xffff)
		{
			c = (char) (0xe0 | (tmp >> 12));
			write (1, &c, 1);
			c = (char) (0x80 | ((tmp >> 6) & 0x3f));
			write (1, &c, 1);
			c = (char) (0x80 | (tmp & 0x3f));
			write (1, &c, 1);
			data->nb_char += 3;
		}
		data->i += 1 + j;
	}
}
