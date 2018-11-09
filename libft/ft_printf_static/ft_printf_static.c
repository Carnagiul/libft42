/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:34:56 by piquerue          #+#    #+#             */
/*   Updated: 2018/11/09 15:46:57 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_static_print(int fd, t_ft_printf_static *ptf)
{
	int	old;

	old = ptf->position;
	ptf->printed += write(fd, ptf->str, 2048);
	ptf->position = 0;
	while (ptf->position < old)
		ptf->str[ptf->position++] = 0;
	ptf->position = 0;
}

int		ft_printf_static_fd(int fd, char *fmt, va_list lst)
{
	static t_ft_printf_static	ptf;

	ptf.position_str = 0;
	ptf.total_printed += ptf.printed;
	ptf.printed = 0;
	while (fmt[ptf.position_str])
	{
		ptf.str[ptf.position] = fmt[ptf.position_str];
		if (ptf.position == 2048)
			ft_printf_static_print(fd, &ptf);
		else
			ptf.position++;
		ptf.position_str++;
	}
	if (ptf.position > 0)
		ft_printf_static_print(fd, &ptf);
	(void)lst;
	return (ptf.printed);
}

int		ft_printf_static(char *fmt, ...)
{
	va_list		lst;

	va_start(lst, fmt);
	return (ft_printf_static_fd(1, fmt, lst));
}