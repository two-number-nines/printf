/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converterDIO.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:12:10 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/02 16:25:34 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	typecastthisshit(t_struct *val, va_list *lp)
{
	if (val->h)
	{
		val->d = (short int)val->d;
		val->d = va_arg(*lp, int);
	}
	else if (val->hh)
	{
		val->d = va_arg(*lp, int);
		val->d = (signed char)val->d;
	}
	else if (val->l)
	{
		val->d = va_arg(*lp, long int);
	}
	else if (val->ll)
		val->d = va_arg(*lp, long long int);
	else
		val->d = va_arg(*lp, int);
	
}

void	ft_converter_dio(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	typecastthisshit(val, lp);
	if (val->width)
		put_width_buf(val);
	if (ft_getdigits(val->d) >= val->width)
		tmp = ft_getdigits(val->d);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft_int(val);
	else
		ft_cpy_to_buf_int(val);
}
