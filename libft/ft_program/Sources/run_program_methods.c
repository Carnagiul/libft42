/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program_methods.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:20:04 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/12 23:41:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				run_program_methods(t_program *program)
{
	pthread_t			thread[2];
	t_program_callback	*callback_timeout;
	t_program_callback	*callback_timeout2;

	callback_timeout = ft_create_program_callback();
	callback_timeout2 = ft_create_program_callback();
	
	callback_timeout->callback = &custom_timeout;
	callback_timeout->data_event = program;
	callback_timeout2->callback = &custom_timeout_2;
	callback_timeout2->data_event = program;
	program->need_stop = 0;
	
	ft_list_push_back(&(program->events), callback_timeout2, sizeof(t_program_callback));
	ft_list_push_back(&(program->events), callback_timeout, sizeof(t_program_callback));

	pthread_create(&thread[0], NULL, (void*)run_program_callback, program);
	pthread_create(&thread[1], NULL, (void*)run_program_events, program);

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	return ;
}