/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkflags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 12:36:26 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 15:51:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkflagsif(t_struct *val)
{
	if (val->fmt[val->i] == '-')
		val->flagmin = 1;
	else if (val->fmt[val->i] == '+')
		val->flagplus = 1;
	else if (val->fmt[val->i] == ' ')
		val->flagspace = 1;
	else if (val->fmt[val->i] == '#')
		val->flaghasj = 1;
	else if (val->fmt[val->i] == '0')
		val->flagnull = 1;
}

void	ft_checkflags(t_struct *val)
{
	while (val->fmt[val->i] == '-' || val->fmt[val->i] == '+'
			|| val->fmt[val->i] == ' ' || val->fmt[val->i] == '#'
			|| val->fmt[val->i] == '0')
	{
		ft_checkflagsif(val);
		val->i++;
	}
}
