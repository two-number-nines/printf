/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:12:10 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 18:53:08 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	typecastthisshit(t_struct *val, va_list *lp)
{
	if (val->h)
	{
		val->d = va_arg(*lp, int);
		(short int)val->d;
	}
	if (val->hh)
	{
		val->d = va_arg(*lp, int);
		(signed char)val->d;
	}
	if (val->l)
		val->d = va_arg(*lp, long int);
	if (val->ll)
		val->d = va_arg(*lp, long long int);
}

void	ft_converter_d(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	typecastthisshit(val, lp);
	if (val->width)
		put_width_buf(val);
	if (ft_getdigits(val->d) >= val->width)
		tmp = ft_getdigits(val->d);
	//if (val->flagmin || tmp)
	//	ft_cpy_to_buf_lft(val, s);
	//else
	//	ft_cpy_to_buf(val, s);
}
