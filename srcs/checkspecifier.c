/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 10:36:25 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	put_width_buf(t_struct *val)
{
	int tmpi;

	tmpi =  val->width;
	while (tmpi)
	{
		val->buf[val->bi] = ' ';
		tmpi--;
		val->bi++;
	}
}

void	ft_converter(t_struct *val)
{
	if (val->width)
	{
		put_width_buf(val);
	}
}

void	ft_checkspecifier(t_struct *val)
{
	//datatypes meesturen naar de converter
	if (val->fmt[val->i] == 'c')
	{
		ft_converter(val);
		val->i++;
	}
}
