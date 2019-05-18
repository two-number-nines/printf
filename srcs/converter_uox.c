/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter_uox.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 16:01:21 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/18 15:07:32 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void	ft_typecaster_u(t_struct *val)
{
	if (val->h)
		val->ud = (unsigned short)val->ud;
	else if (val->hh)
		val->ud = (unsigned char)val->ud;
	else if (val->l)
		val->ud = (unsigned long)val->ud;
	else if (val->ll)
		val->ud = (unsigned long long)val->ud;
	else
		val->ud = (unsigned int)val->ud;
}

void		ft_converter_uox(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->ud = va_arg(*lp, unsigned long long);
	ft_typecaster_u(val);
	put_width_buf(val);
	if (ft_getdigits(val->ud) >= val->width)
		tmp = ft_getdigits(val->ud);
	if (val->flagmin || tmp || (val->precis >= val->width))
		ft_cpy_to_buf_lft_int_u(val);
	else
		ft_cpy_to_buf_int_u(val);
}
