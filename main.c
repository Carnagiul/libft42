/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:32:00 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/12 23:42:13 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			toto = 0;
static int			custom_timeout_is_in_use = 0;
static int			custom_timeout_2_is_in_use = 0;
static t_program	*program;

void				run()
{
	sleep(1);
	ft_printf_static("%s\n", ft_itoa(++toto));
	return ;
}

int					need_stop()
{
	return program->need_stop;
}

void				custom_timeout(t_program_callback *cb)
{
	static struct timeval		now;
	static struct timeval		t;

	if (need_stop() == 1)
		return ;
	if (custom_timeout_is_in_use == 0)
	{
		gettimeofday(&t, NULL);
		custom_timeout_is_in_use = 1;
		t.tv_sec = t.tv_sec + 10;
		return custom_timeout(cb);
	}

	gettimeofday(&now, NULL);

	if (now.tv_sec >= t.tv_sec)
	{
		program->exit_message = ft_strdup("Program Killed By Event after 10 seconds <3");
		program->need_stop = 1;
		program->exit_code = 0;
		custom_timeout_is_in_use = 0;
	}
	else
		sleep(1);
	return custom_timeout(cb);
}

void				custom_timeout_2(t_program_callback *cb)
{
	static struct timeval		now;
	static struct timeval		t;

	if (need_stop() == 1)
		return ;
	if (custom_timeout_2_is_in_use == 0)
	{
		gettimeofday(&t, NULL);
		custom_timeout_2_is_in_use = 1;
		t.tv_sec = t.tv_sec + 5;
		return custom_timeout_2(cb);
	}

	gettimeofday(&now, NULL);

	if (now.tv_sec >= t.tv_sec)
	{
		program->exit_message = ft_strdup("Program Killed By Event after 5 seconds <3");
		program->need_stop = 1;
		program->exit_code = 0;
		custom_timeout_2_is_in_use = 0;
	}
	else
		sleep(1);

	return custom_timeout_2(cb);
}


int					main(void)
{
	program = ft_create_program();
	program->callback = &run;

	run_program_methods(program);
	
	if (program->exit_message != NULL)
		ft_printf("%s\n", program->exit_message);
	return program->exit_code;
}