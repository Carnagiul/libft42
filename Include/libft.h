/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <piquerue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:01:37 by piquerue          #+#    #+#             */
/*   Updated: 2022/02/11 14:54:47 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

typedef unsigned char		t_char;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <fcntl.h>
# include <stdint.h>
# include <dirent.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pthread.h>
# include <math.h>
# include <sys/time.h>

# include <pwd.h>
# include <grp.h>
# include "ft_math.h"
# include "ft_log.h"
# include "ft_files.h"
# include "ft_gnl.h"
# include "ft_display.h"
# include "ft_delimiteur.h"
# include "ft_memory.h"
# include "ft_list.h"
# include "ft_string.h"
# include "ft_utils.h"
# include "ft_printf.h"
# include "ft_printf_static.h"
# include "ft_wstr.h"
# include "ft_program.h"

void			custom_timeout(t_program_callback *cb);
void			custom_timeout_2(t_program_callback *cb);

#endif
