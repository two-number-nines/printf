/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checklengmodif.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:39:53 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/25 15:51:00 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checklenmodif(t_struct *val)
{
	if (val->fmt[val->i] == 'h')
		if (val->fmt[val->i + 1] == 'h')
			val->hh = 1;
		else
			val->h = 1;
	else if (val->fmt[val->i] == 'l')
		if (val->fmt[val->i + 1] == 'l')
			val->ll = 1;
		else
			val->l = 1;
	else if (val->fmt[val->i] == 'L')
		val->L = 1;
}

void	ft_checklenmod(t_struct *val)
{
	while (val->fmt[val->i] == 'h' || val->fmt[val->i] == 'l'
			|| val->fmt[val->i] == 'L')
	{
		if (val->hh == 0 && val->ll == 0)
			ft_checklenmodif(val);
		val->i++;
	}
}
