/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:20:31 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/24 12:32:28 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_ar(t_data *data, char *ar, int j)
{
	if (ar)
		res_join(data, ar, 0); 
	else
		res_join(data, "(null)", 0);
	data->i += 1 + j;
}

void	c_ar(t_data *data, int ar, int j)
{
	char	tmp;

	tmp = ar;
	if (tmp)
		res_join(data, 0, tmp);
	else if (j > 0)
	{
		if (data->nb_char > 0)
		{
			ft_putstr(data->result);
			ft_memdel((void *)&data->result);
			data->result = ft_strnew(0);
		}
		write(1, "\0", 1);
		data->nb_char++;
	}
	else
		data->nb_char++;
	data->i += 1 + j;
}

void	d_ar(t_data *data, int nb, int j)
{
	char *str;

	data->i += 1 + j;
	while (j-- && nb >= 0)
		res_join(data, 0, ' ');
	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
}

void	p_ar(t_data *data, long nb, int j)
{
	char	*hex;
	char	*str;
	int		i;

	i = 0;
	hex = ft_strnew(16);
	str = ft_strnew(16);
	hex = "0123456789abcdef";
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = hex[nb % 16];
		nb /= 16;
	}
	str[i] = 0;
	str = ft_revstr(str);
	res_join(data, "0x", 0);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
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
	int		i;
	char	*str;
	long	deci;

	i = 0;
	deci = (long)nb;
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

void	u_maj_ar(t_data *data, void *ar, int j)
{
	unsigned long	nb;
	char 			*str;

	nb = (unsigned long)ar;
	str = ft_itoa_ulong(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
}

void	x_ar(t_data *data, void *ar, int j, char x)
{
	unsigned long	nb; 
	char			*hex;
	char			*str;
	int				i;

	i = 0;
	hex = ft_strnew(16);
	str = ft_strnew(21);
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	nb = (unsigned long)ar;
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

void	c_maj_ar(t_data *data, void *ar, int j)
{
	wchar_t	tmp;
	char	c;

	tmp = (wchar_t)ar;
	if (tmp <= 0x7f)
		c_ar(data, (int)ar, j);
	else
	{
		if (data->nb_char > 0)
		{
			ft_putstr(data->result);
			ft_memdel((void *)&data->result);
			data->result = ft_strnew(0);
		}
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

void	s_maj_ar(t_data *data, void *ar, int j)
{
	wchar_t			*tmp;
	unsigned char	c;
	int				i;

	i = 0;
	if (!ar)
		return(s_ar(data, NULL, j));
	tmp = (wchar_t *)ar;
	if (data->nb_char > 0)
	{
		ft_putstr(data->result);
		ft_memdel((void *)&data->result);
		data->result = ft_strnew(0);
	}
	while (tmp[i])
	{
		if (tmp[i] <= 0x7f)
			write (1, &tmp[i], 1);
		else if (tmp[i] <= 0x7ff)
		{
			c = (char) (0xc0 | (tmp[i] >> 6));
			write (1, &c, 1);
			c = (char) (0x80 | (tmp[i] & 0x3f));
			write (1, &c, 1);
			data->nb_char ++;
		}
		else if (tmp[i] <= 0xffff)
		{
			c = (char) (0xe0 | (tmp[i] >> 12));
			write (1, &c, 1);
			c = (char) (0x80 | ((tmp[i] >> 6) & 0x3f));
			write (1, &c, 1);
			c = (char) (0x80 | (tmp[i] & 0x3f));
			write (1, &c, 1);  
			data->nb_char += 2;
		}
		data->nb_char ++;
		i++;
	}
	data->i += 1 + j;
}
