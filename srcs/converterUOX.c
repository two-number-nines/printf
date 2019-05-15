/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converterUOX.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 16:01:21 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/15 12:05:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	typecastthisshit_u(t_struct *val)
{
	if (val->h)
		val->ud = (unsigned short int)val->ud;
	else if (val->hh)
		val->ud = (unsigned char)val->ud;
	else if (val->l)
		val->ud = (unsigned long int)val->ud;
	else if (val->ll)
		val->ud = (unsigned long long int)val->ud;
	else
		val->ud = (unsigned int)val->ud;
	
}

void	ft_converter_uox(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->ud = va_arg(*lp, unsigned long long);
	typecastthisshit_u(val);
	put_width_buf(val);
	if (ft_getdigits(val->d) >= val->width)
		tmp = ft_getdigits(val->d);
	if (val->flagmin || tmp || (val->precis >= val->width))
		ft_cpy_to_buf_lft_int_u(val);
	else
		ft_cpy_to_buf_int_u(val);
}
