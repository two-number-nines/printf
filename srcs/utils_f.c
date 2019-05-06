/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:04:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/06 12:55:01 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	if (val->flagplus && val->f >= 0)
	{
		i++;
		val->bi -= i;
		if (val->flagnull)
			val->buf[val->tmpi] = '+';
		else
			val->buf[val->bi] = '+';
		val->bi++;
	}
	else
		val->bi -= i;
}

void	ft_cpy_to_buf_int_f(t_struct *val)
{
	int		i;
	int		j;
	char	*s;
	s =  NULL;
	
	//s = ftoa(val->f, s, 4);
	i = ft_strlen(s);
	j = 0;
	ft_cpy_to_buf_int_if(val, i);
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
}

void	ft_cpy_to_buf_lft_int_f(t_struct *val)
{
	int		j;
	char	*s;

	s = NULL;
	j = 0;
	//s = ftoa(val->f, s, 4);
	val->bi = val->tmpi;
	if (val->flagplus && val->f >= 0)
	{
		val->buf[val->bi] = '+';
		val->bi++;
	}
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
}
