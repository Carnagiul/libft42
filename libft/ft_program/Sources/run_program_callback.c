/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program_callback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:26 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/10 19:57:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void				run_program_callback(t_program *program)
{
	while (program->need_stop == 0)
	{
		program->callback(program);
	}
	
	return ;
}