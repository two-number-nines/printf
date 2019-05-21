/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 12:11:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/21 14:17:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void			ft_set_null(t_struct *val)
{
	int i;

	i = 0;
	while (val->buf[i])
	{
		if (val->buf[i] == -1)
			val->buf[i] = 0;
		i++;
	}
}

void			reset_flags(t_struct *val)
{
	val->flagmin = 0;
	val->flagplus = 0;
	val->flagspace = 0;
	val->flaghasj = 0;
	val->flagnull = 0;
	val->width = 0;
	val->precis = -1;
	val->length = 0;
	val->hh = 0;
	val->h = 0;
	val->l = 0;
	val->ll = 0;
	val->L = 0;
}

void			ft_clearbuf(t_struct *val)
{
		int i;

		if (val->tc)
		{
			i = ft_strlen(val->buf);
			ft_set_null(val);
			val->ret += i;
			write(1, val->buf, i);
		}
		else
		{
			val->ret = val->ret + ft_strlen(val->buf);
			write(1, val->buf, ft_strlen(val->buf));
		}
		val->bi = 0;
		ft_bzero(val->buf, ft_strlen(val->buf));
		val->tc = 0;
}
