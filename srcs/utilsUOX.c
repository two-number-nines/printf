/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsUX.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:56:03 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/02 16:31:32 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	val->bi -= i;
	if (val->flagplus && val->ud > 0)
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

void	ft_cpy_to_buf_int_u(t_struct *val)
{
	int		b;
	int		i;
	int		j;
	char	*s;

	b = ft_supersayenbased(val);
	s = ft_itoa_base_u(val->ud, b);
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

void	ft_cpy_to_buf_lft_int_u(t_struct *val)
{
	int		b;
	int		j;
	char	*s;

	j = 0;
	b = ft_supersayenbased(val);
	s = ft_itoa_base_u(val->ud, b);
	val->bi = val->tmpi;
	if (val->flagplus && val->ud > 0)
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
