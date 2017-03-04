/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:48:37 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/04 01:23:53 by benjamin         ###   ########.fr       */
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
