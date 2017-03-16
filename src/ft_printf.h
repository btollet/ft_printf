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

# define IJ data->i + j

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
	int			less;
	int			zero;
	int			sharp;
	int			precision;
	int			prec_ok;
	int			null;
	int			digit_found;
	int			no_reset;
}				t_data;

int				ft_printf(char *str, ...);
t_data			init();
t_data			check_str(t_data data, char *str, va_list ar);
void			reset_option(t_data *data, char *str, int j, int all);
void			reset_result(t_data *data);
void			get_option(t_data *data, char *str, int j, char last);
void			get_option_part2(t_data *data, char *str, char last);
void			get_digit_option(t_data *data, char *str, char last);
void			get_digit_option_part2(t_data *data, char *str, char last);
void			space(t_data *data, int nb);
void			space_part2(t_data *data, int nb);
void			diese_ar(t_data *data, int j);
void			s_ar(t_data *data, char *ar, int j);
void			c_ar(t_data *data, int ar, int j);
void			d_ar(t_data *data, void *ar, int j, int h);
void			p_ar(t_data *data, long nb, int j);
void			s_maj_ar(t_data *data, void *ar, int j);
void			s_maj_ar_part2(t_data *data, wchar_t *tmp, int len, int j);
void			s_maj_prec(t_data *data, wchar_t *tmp);
void			s_maj_check_prec(t_data *data, wchar_t *tmp, int cpy);
void			s_maj_write(t_data *data, wchar_t str, int nb, int prec);
void			d_maj_ar(t_data *data, void *ar, int j);
void			o_ar(t_data *data, void *nb, int j);
void			o_maj_ar(t_data *data, void *nb, int j);
void			u_ar(t_data *data, void *ar, int j, char u);
void			x_ar(t_data *data, void *ar, int j, char x);
void			c_maj_ar(t_data *data, void *ar, int j);
void			lo_ar(t_data *data, void *nb, int j);
void			lx_ar(t_data *data, void *ar, int j, char x);
void			ho_ar(t_data *data, void *nb, int j);
void			hhd_ar(t_data *data, void *ar, int j);
void			hhu_ar(t_data *data, void *ar, int j);
void			hho_ar(t_data *data, void *nb, int j);
void			hho_maj_ar(t_data *data, void *nb, int j);
void			hhx_ar(t_data *data, void *ar, int j, char x);
void			sharp_o_ar(t_data *data, void *nb, int j);
void			sharp_o_maj_ar(t_data *data, void *nb, int j);
void			res_join(t_data *data, char *str, char c);
void			res_join_part2(t_data *data, char *str, char c, int len);
void			check_arg(t_data *data, char *str, va_list ar, int j);
void			check_arg_part2(t_data *data, char *str, va_list ar, int j);
void			check_l_arg(t_data *data, char *str, va_list ar, int j);
void			check_l_arg_pat2(t_data *data, char *str, va_list ar, int j);
void			check_h_arg(t_data *data, char *str, va_list ar);
void			check_hh_arg(t_data *data, char *str, va_list ar);
void			check_hh_arg_part2(t_data *data, char *str, va_list ar);
void			check_sharp_arg(t_data *data, char *str, va_list ar);
void			write_only(t_data *data, char c);

#endif
