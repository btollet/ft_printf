/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s_maj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:31:02 by btollet           #+#    #+#             */
/*   Updated: 2017/03/16 18:31:04 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_maj_ar(t_data *data, void *ar, int j)
{
	wchar_t			*tmp;
	int				i;
	int				len;

	i = 0;
	len = 0;
	if (!ar)
		return (s_ar(data, NULL, j));
	tmp = (wchar_t *)ar;
	while (tmp[i])
	{
		if (tmp[i] <= 0x7ff)
			len++;
		else if (tmp[i] <= 0xffff)
			len += 2;
		len++;
		i++;
	}
	s_maj_ar_part2(data, tmp, len, j);
}

void	s_maj_ar_part2(t_data *data, wchar_t *tmp, int len, int j)
{
	if (data->option - len > 0)
	space(data, data->option - len);
	reset_result(data);
	if (data->prec_ok == 1)
		s_maj_prec(data, tmp);
	else
	{
		while (*tmp)
		{
			if (*tmp <= 0x7f)
				s_maj_write(data, *tmp, 1, 0);
			else if (*tmp <= 0x7ff)
				s_maj_write(data, *tmp, 2, 0);
			else if (*tmp <= 0xffff)
				s_maj_write(data, *tmp, 3, 0);
			else
				break ;
			tmp++;
		}
	}
	if (data->option + len < 0)
		space(data, -(data->option + len));
	data->i += 1 + j;
}

void	s_maj_prec(t_data *data, wchar_t *tmp)
{
	int		cpy;

	cpy = data->option;
	if (data->precision > 0)
		s_maj_check_prec(data, tmp, cpy);
	while (*tmp)
	{
		if (*tmp <= 0x7f && data->option >= 1)
			s_maj_write(data, *tmp, 1, 1);
		else if (*tmp <= 0x7ff && data->option >= 2)
			s_maj_write(data, *tmp, 2, 1);
		else if (*tmp <= 0xffff && data->option >= 3)
			s_maj_write(data, *tmp, 3, 1);
		else
			break ;
		tmp++;
	}
}

void	s_maj_check_prec(t_data *data, wchar_t *tmp, int cpy)
{
	while (*tmp)
	{
		if (*tmp <= 0x7ff && cpy >= 2)
		{
			cpy--;
			data->precision--;
		}
		else if (*tmp <= 0xffff && cpy >= 3)
		{
			cpy -= 2;
			data->precision -= 2;
		}
		else if (!(*tmp <= 0x7f && cpy >= 1))
			break ;
		cpy--;
		data->precision--;
		tmp++;
	}
	while (data->precision-- > 0)
		if (data->zero == 1)
			write_only(data, '0');
		else
			write_only(data, ' ');
}

void	s_maj_write(t_data *data, wchar_t str, int nb, int prec)
{
	char	c;

	if (nb == 1)
		write_only(data, str);
	if (nb == 2)
	{
		c = (char)(0xc0 | (str >> 6));
		write_only(data, c);
		c = (char)(0x80 | (str & 0x3f));
		write_only(data, c);
	}
	else if (nb == 3)
	{
		c = (char)(0xe0 | (str >> 12));
			write_only(data, c);
			c = (char)(0x80 | ((str >> 6) & 0x3f));
			write_only(data, c);
			c = (char)(0x80 | (str & 0x3f));
			write_only(data, c);
	}
	if (prec == 1)
		data->option -= nb;
}
