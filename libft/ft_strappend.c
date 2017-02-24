/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:10:39 by benjamin          #+#    #+#             */
/*   Updated: 2017/02/22 20:11:13 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strappend(char *file, char *buf)
{
	char	*result;

	result = ft_strjoin(file, buf);
	ft_memdel((void *)&file);
	return (result);
}
