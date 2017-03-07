/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:58:21 by benjamin          #+#    #+#             */
/*   Updated: 2017/03/07 17:36:38 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	char		*result;
	char		*hex;
	int			i;
	int			nb_char;
	int			option;
	char		c_option;
	int			plus;
	int			sharp;
}				t_data;

int				ft_printf(char *str, ...);
t_data			init();
t_data			check_str(t_data data, char *str, va_list ar);
void			get_option(t_data *data, char *str, int j);
void			space(t_data *data, int nb);
void			s_ar(t_data *data, char *ar, int j);
void			c_ar(t_data *data, int ar, int j);
void			d_ar(t_data *data, int nb, int j);
void			p_ar(t_data *data, long nb, int j);
void			s_maj_ar(t_data *data, void *ar, int j);
void			d_maj_ar(t_data *data, void *ar, int j);
void			o_ar(t_data *data, void *nb, int j);
void			o_maj_ar(t_data *data, void *nb, int j);
void			u_ar(t_data *data, void *ar, int j);
void			u_maj_ar(t_data *data, void *ar, int j);
void			x_ar(t_data *data, void *ar, int j, char x);
void			c_maj_ar(t_data *data, void *ar, int j);
void			lo_ar(t_data *data, void *nb, int j);
void			lx_ar(t_data *data, void *ar, int j, char x);
void			hhd_ar(t_data *data, void *ar, int j);
void			hhu_ar(t_data *data, void *ar, int j);
void			hho_ar(t_data *data, void *nb, int j);
void			hho_maj_ar(t_data *data, void *nb, int j);
void			hhx_ar(t_data *data, void *ar, int j, char x);
void			sharp_o_ar(t_data *data, void *nb, int j);
void			sharp_o_maj_ar(t_data *data, void *nb, int j);
void			res_join(t_data *data, char *str, char c);
void			check_arg(t_data *data, char *str, va_list ar, int j);
void			check_l_arg(t_data *data, char *str, va_list ar);
void			check_h_arg(t_data *data, char *str, va_list ar);
void			check_hh_arg(t_data *data, char *str, va_list ar);
void			check_sharp_arg(t_data *data, char *str, va_list ar);


#endif