/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:33:29 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/25 16:48:39 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h> ///////delete this
# include "../libft/libft.h"

# define BUFF_FULL 999
# define FLAG_MIN (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_HASJ (1 << 4)
# define FLAG_NULL (1 << 5)

typedef struct	s_struct {
	short			flags;
	int				bi;
	int				i;
	const char		*fmt;
	int				width;
	int				precis;
	int				length;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				L;
	char			speficier;
	char			buf[1000];
}					t_struct;

/*
** checkflags.c
*/

void	ft_checkflags(t_struct *val);

/*
** checkwidth.c
*/

void	ft_checkwidth(t_struct *val, va_list lp);

/*
** checkpresicion.c
*/

void	ft_checkprecision(t_struct *val, va_list lp);

/*
** ft_checklenmodif.c
*/

void	ft_checklenmod(t_struct *val);

/*
**		ft_checkspecifier.c
*/

void	ft_checkspecifier(t_struct *val);

#endif