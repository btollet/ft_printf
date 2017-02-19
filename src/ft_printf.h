/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:58:21 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/19 20:56:39 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define	INT_MIN		(-2147483647-1)

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	int			i;
	int			nb_char;	
}				t_data;

int				ft_printf(char *str, ...);
t_data			init();
int				check_str(t_data data, char *str, va_list ar);
void			s_ar(t_data *data, char *ar);
void			d_ar(t_data *data, int nb);

#endif