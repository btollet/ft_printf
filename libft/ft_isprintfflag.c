/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintfflag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 06:59:24 by btollet           #+#    #+#             */
/*   Updated: 2017/03/10 06:59:30 by btollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprintfflag(int c)
{
	if (ft_isdigit(c) || c == '-' || c == '+' || c == '#' || c == '.')
		return (1);
	return (0);
}

