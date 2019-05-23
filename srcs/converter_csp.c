/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter_csp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 17:52:57 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 11:33:29 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_converter_c(t_struct *val, va_list *lp)
{
	char c;

	c = va_arg(*lp, int);
	if (c == 0)
	{
		val->tc = 1;
		c = -1;
	}
	if (val->width)
		put_width_buf(val);
	if (val->flagmin)
		val->buf[val->tmpi] = c;
	else if (val->width > 0)
		val->buf[val->bi - 1] = c;
	else
		val->buf[val->bi] = c;
}

void	ft_converter_s(t_struct *val, va_list *lp)
{
	char	*s;
	int		i;
	int		tmp;

	i = 0;
	s = va_arg(*lp, char*);
	if (s == NULL)
		s = "(null)";
	if (val->precis == 0)
		return ;
	tmp = 0;
	if (val->width)
		put_width_buf(val);
	if (val->precis >= val->width)
		if ((int)ft_strlen(s) > val->width)
			tmp = ft_strlen(s);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft(val, s);
	else
		ft_cpy_to_buf(val, s);
}

void	ft_converter_p(t_struct *val, va_list *lp)
{
	long long	p;
	char		*s;
	int			tmp;

	p = va_arg(*lp, long long);
	tmp = 0;
	s = long_to_a_string(p);
	if (val->width)
		put_width_buf(val);
	if ((int)ft_strlen(s) >= val->width)
		tmp = ft_strlen(s);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft(val, s);
	else
		ft_cpy_to_buf(val, s);
}
