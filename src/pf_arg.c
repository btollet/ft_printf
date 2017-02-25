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
	else
		data->nb_char++;
	data->i += 1 + j;
}

void	d_ar(t_data *data, int nb, int j)
{
	char *str;

	str = ft_itoa(nb);
	res_join(data, str, 0);
	ft_memdel((void *)&str);
	data->i += 1 + j;
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
	data->i += 1 + j;
}
#include <stdio.h>
#include <math.h>

void	s_maj_ar(t_data *data, void *ar, int j)
{
	char *tmp;
	unsigned char c;

	int i;
	int codepoint = 1;

	i = 0;
	if (!ar)
		return(s_ar(data, NULL, j));
	tmp = ar;
	if (data->nb_char > 0)
	{
		ft_putstr(data->result);
		ft_memdel((void *)&data->result);
		data->result = ft_strnew(0);
	}
	while (tmp[i])
	{

		if (i >= 1)
			codepoint += (tmp[i] * i * 256) - 1;
		else
			codepoint += tmp[i];
		i++;
	}
	//printf("Number: %d\n, %d , %d", codepoint, tmp[0], tmp[1]);
	if (codepoint <= 0x7f)
	{
		printf("1\n");
       write (1, &c, 1);
	}
    else if (codepoint <= 0x7ff) {
      	c = (char) (0xc0 | (codepoint >> 6));
      	write (1, &c, 1);
       	c = (char) (0x80 | (codepoint & 0x3f));
       	write (1, &c, 1);
    }
	else if (codepoint <= 0xffff)
	{
		c = (char) (0xe0 | (codepoint >> 12));
		write (1, &c, 1);
		c = (char) (0x80 | ((codepoint >> 6) & 0x3f));
		write (1, &c, 1);
		c = (char) (0x80 | (codepoint & 0x3f));
		write (1, &c, 1);  
    }
    else if (codepoint <= 0x1fffff) {
    	ft_putendl("4");
       // (char) (0xf0 | (codepoint >> 18)),
         // (char) (0x80 | ((codepoint >> 12) & 0x3f),
        // (char) (0x80 | ((codepoint >> 6) & 0x3f),
         // (char) (0x80 | (codepoint & 0x3f));
    }
    else
        ft_putendl("NO");
	data->i += 1 + j;
	data->nb_char += 3;
}
