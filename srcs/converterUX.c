/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converterUX.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 16:01:21 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/02 16:26:35 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_converter_ux(t_struct *val, va_list *lp)
{
	int		tmp;

	tmp = 0;
	val->ud = va_arg(*lp, unsigned int);
	typecastthisshit(val, lp);
	if (val->width)
		put_width_buf(val);
	if (ft_getdigits(val->d) >= val->width)
		tmp = ft_getdigits(val->d);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft_int_u(val);
	else
		ft_cpy_to_buf_int_u(val);
}
