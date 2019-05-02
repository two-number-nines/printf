/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsDIO.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/02 15:54:56 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

int		ft_supersayenbased(t_struct *val)
{
	if (val->fmt[val->i] == 'o')
		return (8);
	else if (val->fmt[val->i] == 'x')
		return (16);
	return (10);
}

void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	val->bi -= i;
	if (val->flagplus && val->d >= 0)
	{
		i++;
		val->bi -= i;
		if (val->flagnull)
			val->buf[val->tmpi] = '+';
		else
			val->buf[val->bi] = '+';
		val->bi++;
	}
}

void	ft_cpy_to_buf_int(t_struct *val)
{
	int		b;
	int		i;
	int		j;
	char	*s;

	b = ft_supersayenbased(val);
	s = ft_itoa_base_u(val->d, b);
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

void	ft_cpy_to_buf_lft_int(t_struct *val)
{
	int		b;
	int		j;
	char	*s;

	j = 0;
	b = ft_supersayenbased(val);
	s = ft_itoa_base_u(val->d, b);
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
