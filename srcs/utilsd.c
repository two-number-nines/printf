/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/01 12:22:41 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_cpy_to_buf_int(t_struct *val)
{
	int		i;
	int		j;
	char	*s;

	s = ft_itoa(val->d);
	i = ft_strlen(s);
	j = 0;
	if (val->flagplus && val->d >= 0)
	{
		i++;
		val->bi -= i;
		val->buf[val->bi] = '+';
		val->bi++;
	}
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
}

void	ft_cpy_to_buf_lft_int(t_struct *val)
{
	int		j;
	char	*s;

	j = 0;
	s = ft_itoa(val->d);
	val->bi = val->tmpi;
	if (val->flagplus && val->d >= 0)
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
