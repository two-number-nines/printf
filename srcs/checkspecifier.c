/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 18:25:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	put_width_buf(t_struct *val)
{
	val->tmpi = val->bi;
	while (val->width)
	{
		if (val->flagnull)
			val->buf[val->bi] = '0';
		else
			val->buf[val->bi] = ' ';
		val->width--;
		val->bi++;
	}
}

void	ft_cpy_to_buf(char buf[], int *i, char **s)
{
	int j;

	j = 0;
	while ((*s)[j])
	{
		(*buf) = (*s)[j];
		(*i)++;
		j++;
	}
}

void	ft_checkspecifier(t_struct *val, va_list *lp)
{
	if (val->fmt[val->i] == 'c')
		ft_converter_c(val, lp);
	else if (val->fmt[val->i] == 's')
		ft_converter_s(val, lp);
	val->i++;
}
