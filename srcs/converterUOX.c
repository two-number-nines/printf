/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converterUOX.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 16:01:21 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/04 16:12:33 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	typecastthisshit_u(t_struct *val)
{
	if (val->h)
		val->ud = (short int)val->ud;
	else if (val->hh)
		val->ud = (signed char)val->ud;
	else if (val->l)
		val->ud = (long int)val->ud;
	else if (val->ll)
		val->ud = (long long int)val->ud;
	return ;
	
}

void	ft_converter_uox(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->ud = va_arg(*lp, unsigned long long);
	typecastthisshit_u(val);
	if (val->width)
		put_width_buf(val);
	if (ft_getdigits_u(val->ud) >= val->width)
		tmp = ft_getdigits_u(val->ud);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft_int_u(val);
	else
		ft_cpy_to_buf_int_u(val);
}
