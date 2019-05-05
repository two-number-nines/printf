/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/05 14:47:30 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkspecifier(t_struct *val, va_list *lp)
{
	val->tmpi = val->bi;
	if (val->fmt[val->i] == 'c')
		ft_converter_c(val, lp);
	else if (val->fmt[val->i] == 's')
		ft_converter_s(val, lp);
	else if (val->fmt[val->i] == 'p')
		ft_converter_p(val, lp);
	else if (val->fmt[val->i] == '%')
		ft_converter_perc(val);
	else if (val->fmt[val->i] == 'd' || val->fmt[val->i] == 'i')
		ft_converter_di(val, lp);
	else if (val->fmt[val->i] == 'u' || val->fmt[val->i] == 'x' ||
			val->fmt[val->i] == 'o' || val->fmt[val->i] == 'X')
			{
				val->specifier = val->fmt[val->i];
				ft_converter_uox(val, lp);
			}
	val->i++;
}
