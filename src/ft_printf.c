/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:48:37 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/23 20:55:37 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_data	data;
	va_list	ar;

	data = init();
	va_start(ar, str);
	data = check_str(data, str, ar);
	if (data.nb_char > 0)
		ft_putstr(data.result);
	ft_memdel((void *)&data.result);
	return (data.nb_char);
}

void	res_join(t_data *data, char *str, char c)
{
	char *tmp;

	if (str)
	{
		data->result = ft_strappend(data->result, str);		
		data->nb_char += (ft_strlen(str));
	}
	if (c)
	{
		tmp = ft_strnew(1);
		*tmp = c;
		data->result = ft_strappend(data->result, tmp);
		ft_memdel((void *)&tmp);
		data->nb_char ++;
	}
}
