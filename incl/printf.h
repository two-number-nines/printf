/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:33:29 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/24 11:45:54 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h> ///////delete this
# include "../libft/libft.h"

typedef struct	s_struct {
	int			i;
	const char	*format;
	va_list		listpointer;
	int			flags;
	int			width;
	int			precision;
	int			length;
	char		buf[1000];
}				t_struct;

#endif