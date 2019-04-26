/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkwidth.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 15:28:12 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 16:45:22 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkwidthif(t_struct *val, va_list *lp)
{
	if (val->fmt[val->i] >= '0' && val->fmt[val->i] <= '9')
		val->width = val->width * 10 + (val->fmt[val->i] - '0');
	else if (val->fmt[val->i] == '*')
		val->width = va_arg(*lp, int);
}

void	ft_checkwidth(t_struct *val, va_list *lp)
{
	while ((val->fmt[val->i] >= '0' && val->fmt[val->i] <= '9')
			|| val->fmt[val->i] == '*')
	{
		ft_checkwidthif(val, lp);
		val->i++;
	}
}
