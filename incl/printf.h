/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:33:29 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/17 14:14:20 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h> ///////delete this
# include "../libft/libft.h"

# define BUFF_FULL 999

typedef struct			s_struct {
	double				f; 
	signed long long	d;
	unsigned long long	ud;
	int					tmpi;
	int					flagmin;
	int					flagplus;
	int					flagspace;
	int					flaghasj;
	int					flagnull;
	int					bi;
	int					i;
	const char			*fmt;
	int					width;
	int					precis;
	int					length;
	int					hh;
	int					h;
	int					l;
	int					ll;
	int					L;
	char				specifier;
	char				buf[1000];
	int					ret;
}						t_struct;

int		ft_printf(const char *format, ...);

/*
**		checks
*/

void	ft_checkflags(t_struct *val);
void	ft_checkwidth(t_struct *val, va_list *lp);
void	ft_checkprecision(t_struct *val, va_list *lp);
void	ft_checklenmod(t_struct *val);
void	ft_checkspecifier(t_struct *val, va_list *lp);

/*
**		converters
*/

void	ft_converter_c(t_struct *val, va_list *lp);
void	ft_converter_s(t_struct *val, va_list *lp);
void	ft_converter_p(t_struct *val, va_list *lp);
void	ft_converter_perc(t_struct *val);
void	ft_converter_di(t_struct *val, va_list *lp);
void	ft_converter_uox(t_struct *val, va_list *lp);
void	ft_converter_f(t_struct *val, va_list *lp);


/*
**		utils.c
*/

void	ft_cpy_to_buf(t_struct *val, char *s);
void	ft_cpy_to_buf_lft(t_struct *val, char *s);
void	put_width_buf(t_struct *val);
char	*long_to_a_string(long long l);

/*
**		utilsd.c
*/

void	ft_cpy_to_buf_lft_int(t_struct *val);
void	ft_cpy_to_buf_int(t_struct *val);
int		ft_supersayenbased(t_struct *val);

/*
**		utilsUX.c
*/

void	ft_cpy_to_buf_lft_int_u(t_struct *val);
void	ft_cpy_to_buf_int_u(t_struct *val);

/*
**		utils_f.c
*/

void	ft_cpy_to_buf_lft_int_f(t_struct *val);
void	ft_cpy_to_buf_int_f(t_struct *val);
char	*ftoa(float n, char *res, int afterpoint);

/*
**		utilsmain.c
*/

void	reset_flags(t_struct *val);

#endif