/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsUOX.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:56:03 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/05 15:08:01 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	if (val->flaghasj && val->specifier == 'o')
	{
		i++;
		val->bi -= i;
		val->buf[val->bi] = '0';
		val->bi++;
	}
	else if (val->flaghasj && val->specifier == 'x')
	{
		i += 2;
		val->bi -= i;
		val->buf[val->bi] = '0';
		val->bi++;
		val->buf[val->bi] = 'x';
		val->bi++;
	}
	else if (val->flaghasj && val->specifier == 'X')
	{
		i += 2;
		val->bi -= i;
		val->buf[val->bi] = '0';
		val->bi++;
		val->buf[val->bi] = 'X';
		val->bi++;
	}
	else
		val->bi -= i;
}

static void	ft_cpy_to_buf_lft_int_u_if(t_struct *val)
{
	if (val->flaghasj && val->specifier == 'o')
	{
		val->buf[val->bi] = '0';
		val->bi++;
	}
	else if (val->flaghasj && val->specifier == 'x')
	{
		val->buf[val->bi] = '0';
		val->bi++;
		val->buf[val->bi] = 'x';
		val->bi++;
	}
	else if (val->flaghasj && val->specifier == 'X')
	{
		val->buf[val->bi] = '0';
		val->bi++;
		val->buf[val->bi] = 'X';
		val->bi++;
	}
}

void		ft_cpy_to_buf_int_u(t_struct *val)
{
	int		b;
	int		i;
	int		j;
	char	*s;

	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u_x(val->ud, b);
	else 
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

void		ft_cpy_to_buf_lft_int_u(t_struct *val)
{
	int		b;
	int		j;
	char	*s;

	j = 0;
	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u_x(val->ud, b);
	else 
		s = ft_itoa_base_u(val->ud, b);
	val->bi = val->tmpi;
	ft_cpy_to_buf_lft_int_u_if(val);
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
}
