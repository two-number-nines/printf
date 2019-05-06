/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsDI.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/06 16:10:28 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

int		ft_supersayenbased(t_struct *val)
{
	if (val->fmt[val->i] == 'o')
		return (8);
	else if (val->fmt[val->i] == 'x' || val->fmt[val->i] == 'X')
		return (16);
	return (10);
}

void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	if (val->precis)
		i = val->precis;
	if (val->flagplus || val->d < 0)
	{
		i++;
		val->bi -= i;
		if (val->flagnull)
		{
			if (val->flagplus && val->d > 0)
				val->buf[val->tmpi] = '+';
			else
				val->buf[val->tmpi] = '-';
		}
		else
		{
			if (val->flagplus && val->d > 0)
				val->buf[val->bi] = '+';
			else
				val->buf[val->bi] = '-';
		}
		val->bi++;
	}
	else
		val->bi -= i;
}
/*
	if (val->flagplus || val->d < 0)
	{
		if (val->flagplus && val->d > 0)
			val->buf[val->bi] = '+';
		else
			val->buf[val->bi] = '-';
			*/
void	ft_cpy_to_buf_int(t_struct *val)
{
	int		i;
	int		j;
	char	*s;
	int		a;

	a = val->precis;
	s = ft_itoa(val->d);
	i = ft_strlen(s);
	j = 0;
	ft_cpy_to_buf_int_if(val, i);
	while (val->precis - i > 0)
	{
		val->buf[val->bi] = '0';
		val->bi++;
		val->precis--;
	}
	while (s[j])
	{
		if (!(s[j] == '-' && a))
			val->buf[val->bi] = s[j];
		else
			val->buf[val->bi] = '0';
		val->bi++;
		j++;
	}
}

void	ft_cpy_to_buf_lft_int(t_struct *val)
{
	int		j;
	char	*s;
	int		i;
	int		a;

	j = 0;
	a = val->precis;
	s = ft_itoa(val->d);
	i = ft_strlen(s);
	val->bi = val->tmpi;
	if (val->flagplus || val->d < 0)
	{
		if (val->flagplus && val->d > 0)
			val->buf[val->bi] = '+';
		else
			val->buf[val->bi] = '-';
		val->bi++;
	}
	while (val->precis - i > 0)
	{
		val->buf[val->bi] = '0';
		val->bi++;
		val->precis--;
	}
	while (s[j])
	{
		if (!(s[j] == '-' && a))
			val->buf[val->bi] = s[j];
		else
			val->buf[val->bi] = '0';
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
}
