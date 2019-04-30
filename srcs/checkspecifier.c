/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 11:50:56 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkspecifier(t_struct *val, va_list *lp)
{
	if (val->fmt[val->i] == 'c')
		ft_converter_c(val, lp);
	else if (val->fmt[val->i] == 's')
		ft_converter_s(val, lp);
	else if (val->fmt[val->i] == 'p')
		ft_converter_p(val, lp);
	val->i++;
}
