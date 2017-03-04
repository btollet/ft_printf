/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 01:23:30 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/04 02:02:49 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	res_join(t_data *data, char *str, char c)
{
	char	*tmp;
	int		len;

	if (str)
	{
		len = ft_strlen(str);
		if (data->option - len > 0)
			space(data, data->option - len);
		data->result = ft_strappend(data->result, str);		
		data->nb_char += (len);
		if (data->option + len < 0)
			space(data, -(data->option + len));
	}
	if (c)
	{
		if (data->option - 1 > 0)
			space(data, data->option - 1);
		tmp = ft_strnew(1);
		*tmp = c;
		data->result = ft_strappend(data->result, tmp);
		ft_memdel((void *)&tmp);
		data->nb_char ++;
		if (data->option + 1 < 0)
			space(data, -(data->option + 1));
	}
	data->option = 0;
}

void	space(t_data *data, int nb)
{
	char *str;

	if (nb > 0)
	{
		data->nb_char += nb;
		str = ft_strnew(nb);
		while (--nb >= 0)
			str[nb] = ' ';
		data->result = ft_strappend(data->result, str);
		ft_memdel((void *)&str);
		data->option = 0;
	}
}
