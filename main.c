/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:32:00 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/04 16:55:17 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				run(void)
{
	ft_printf_static("Je suis une schtroumpfette \n %s \n", "Ceci es une seconde ligne qui forme avec l'ancienne moins de 2048 characteres!");
	return ;
}

int					main(void)
{
	t_program		*program;

	program = ft_create_program();
	program->callback = &run;
	while (program->need_stop == 0)
	{
		program->callback();
	}
	return program->exit_code;
}