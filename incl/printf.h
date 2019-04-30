/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:33:29 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 18:46:05 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h> ///////delete this
# include "../libft/libft.h"

# define BUFF_FULL 999

typedef struct		s_struct {
	int				d;
	int				tmpi;
	int				flagmin;
	int				flagplus;
	int				flagspace;
	int				flaghasj;
	int				flagnull;
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

void	ft_checkwidth(t_struct *val, va_list *lp);

/*
** checkpresicion.c
*/

void	ft_checkprecision(t_struct *val, va_list *lp);

/*
** ft_checklenmodif.c
*/

void	ft_checklenmod(t_struct *val);

/*
**		ft_checkspecifier.c
*/

void	ft_checkspecifier(t_struct *val, va_list *lp);

/*
**		converter.c
*/

void	ft_converter_c(t_struct *val, va_list *lp);
void	ft_converter_s(t_struct *val, va_list *lp);
void	ft_converter_p(t_struct *val, va_list *lp);
void	ft_converter_perc(t_struct *val);

/*
**		utils.c
*/

void	ft_cpy_to_buf(t_struct *val, char *s);
void	ft_cpy_to_buf_lft(t_struct *val, char *s);
void	put_width_buf(t_struct *val);
char	*long_to_a_string(long long l);

#endif