/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkflags.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 12:36:26 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/24 16:56:10 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkflagsif(t_struct *val)
{
	if (val->fmt[val->i] == '-')
		val->flags = val->flags | FLAG_MIN;
	else if (val->fmt[val->i] ==  '+')
		val->flags = val->flags | FLAG_PLUS;
	else if (val->fmt[val->i] == ' ')
		val->flags = val->flags | FLAG_SPACE;
	else if (val->fmt[val->i] == '#')
		val->flags = val->flags | FLAG_HASJ;
	else if (val->fmt[val->i] == 0)
		val->flags = val->flags | FLAG_NULL;
}

void	ft_checkflags(t_struct *val)
{
	while (val->fmt[val->i] == '-' || val->fmt[val->i] ==  '+'
			|| val->fmt[val->i] == ' ' || val->fmt[val->i] == '#'
			|| val->fmt[val->i] == 0)
			{
				ft_checkflagsif(val);
				val->i++;
			}
}
