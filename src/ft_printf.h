/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:58:21 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/24 12:30:44 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	char		*result;
	int			i;
	int			nb_char;	
}				t_data;

int				ft_printf(char *str, ...);
t_data			init();
t_data			check_str(t_data data, char *str, va_list ar);
void			s_ar(t_data *data, char *ar, int j);
void			c_ar(t_data *data, int ar, int j);
void			d_ar(t_data *data, int nb, int j);
void			p_ar(t_data *data, long nb, int j);
void			s_maj_ar(t_data *data, long ar, int j);
void			res_join(t_data *data, char *str, char c);
void			check_arg(t_data *data, char *str, va_list ar, int j);

#endif