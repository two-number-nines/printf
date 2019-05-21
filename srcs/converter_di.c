/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter_di.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:12:10 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/21 14:24:52 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_typecaster(t_struct *val)
{
	if (val->h)
		val->d = (short int)val->d;
	else if (val->hh)
		val->d = (signed char)val->d;
	else if (val->l)
		val->d = (long int)val->d;
	else if (val->ll)
		val->d = (long long)val->d;
	else
		val->d = (int)val->d;
}

void	ft_converter_di(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->d = va_arg(*lp, long long);
	ft_typecaster(val);
	put_width_buf(val);
	if (ft_getdigits(val->d) >= val->width)
		tmp = ft_getdigits(val->d);
	if (val->flagmin || tmp || (val->precis >= val->width))
		ft_cpy_to_buf_lft_int(val);
	else
		ft_cpy_to_buf_int(val);
}

void	ft_converter_perc(t_struct *val)
{
	int		tmp;

	tmp = 0;
	if (val->fmt[val->i + 1] == '%')
		return ;
	put_width_buf(val);
	if (val->flagmin)
		val->bi = val->tmpi;
	else
	{
		if (val->bi != 0 && val->width)
			val->bi -= 1;
	}
	val->buf[val->bi] = '%';
	val->bi++;
	if (val->flagmin)
		val->bi = val->width + val->tmpi;
}
