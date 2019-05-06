/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter_f.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 10:34:36 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/06 11:22:33 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static int		ft_getdigits_f(long double c)
{
	int i;

	i = 1;
	if (c < 0)
	{
		c *= -1;
		i += 1;
	}
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i);
}

static void	typecastthisshit_f(t_struct *val)
{
	if (val->l)
		val->f = (long int)val->f;
	else if (val->L)
		val->f = (long double)val->f;
	return ;
}

void	ft_converter_f(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->f = va_arg(*lp, long double);
	typecastthisshit_f(val);
	if (val->width)
		put_width_buf(val);
	if (ft_getdigits_f(val->f) >= val->width)
		tmp = ft_getdigits_f(val->f);
	if (val->flagmin || tmp || val->precis >= val->width)
		ft_cpy_to_buf_lft_int_f(val);
	else
		ft_cpy_to_buf_int_f(val);
}
