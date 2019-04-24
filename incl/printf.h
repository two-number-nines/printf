/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:33:29 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/24 14:58:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h> ///////delete this
# include "../libft/libft.h"

# define FLAG_MIN (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_HASJ (1 << 4)
# define FLAG_NULL (1 << 5)

typedef struct	s_struct {
	short		flags;
	int			i;
	const char	*fmt;
	int			width;
	int			precision;
	int			length;
	char		speficier;
	char		buf[1000];
}				t_struct;

/*
** main.c
*/

void	ft_checkflags(t_struct *val);


#endif