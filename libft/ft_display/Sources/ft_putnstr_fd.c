/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 00:19:24 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/19 00:20:00 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnstr_fd(const char *str, int len, int fd)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	if (strlen >= (size_t)len)
	{
		if (write(fd, str, len))
		{
			
		}
	}	
	else
	{
		if (write(fd, str, strlen))
		{
			
		}
	}

}
