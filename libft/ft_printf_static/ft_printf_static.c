/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:34:56 by piquerue          #+#    #+#             */
/*   Updated: 2018/11/09 10:47:49 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_ft_printf_static
{
	char			str[2048];
	int				position_str;
	int				position;
	int				printed;
	int				total_printed;
}					t_ft_printf_static;

int		ft_printf_static_fd(int fd, char *fmt, va_list lst)
{
	static s_ft_printf_static	ptf;

	ptf.position_str = 0;
	ptf.total_printed += ptf.printed;
	ptf.printed = 0;
	while (fmt[ptf.position_str])
	{
		if (ptf.position == 2048)
		{
			ptf.printed += write(fd, ptf.str, 2048);
			ptf.position = 0;
			while (ptf.position < 2048)
				ptf.str[ptf.position++] = 0;
			ptf.position = 0;
		}
	}
	return (ptf.printed);
}

int		ft_printf_static(char *fmt, ...)
{
	va_list		lst;

	va_start(lst, fmt);
	return (ft_printf_static_fd(0, fmt, lst);
}
