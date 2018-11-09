/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_web_init_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:31:04 by piquerue          #+#    #+#             */
/*   Updated: 2018/11/09 10:34:38 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_web_init_header(char *title)
{
	ft_printf("<html>\n");
	ft_printf("\t<head>\n");
	ft_printf("\t\t<meta charset='utf-8'>\n");
	ft_printf("\t\t<title>%s</title>\n");
	ft_printf("\t</head>\n");
}
