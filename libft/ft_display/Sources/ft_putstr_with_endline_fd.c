/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_endline_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:19:06 by piquerue          #+#    #+#             */
/*   Updated: 2016/12/18 20:22:45 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_with_endline_fd(char const *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (write(fd, str, len))
	{
		if (str[len - 1] != '\n')
			ft_putchar_fd('\n', fd);
	}
}