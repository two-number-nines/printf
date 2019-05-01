/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/01 14:37:11 by vmulder       ########   odam.nl         */
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
	else if (val->fmt[val->i] == 'd' || val->fmt[val->i] == 'i' ||
			val->fmt[val->i] == 'o' || val->fmt[val->i] == 'u')
		ft_converter_diou(val, lp);
	val->i++;
}
