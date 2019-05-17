/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_uox.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:56:03 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/17 19:24:10 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"
static char *ft_fix_precis(t_struct *val, char *s)
{
	char	*ns;
	int		i;
	int		tp;

	i = 0;
	tp = 0;
	if (val->precis > (int)ft_strlen(s))
		tp = val->precis - ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * tp + ft_strlen(s) + 1);
	if (val->ud == 0 && val->precis == 0)
	{
		ns[i] = '\0';
		return (ns);
	}
	if (val->flaghasj && val->specifier == 'o')
		ns[i] = '0';
	if (val->flaghasj && val->specifier == 'x')
	{
		if (val->precis < 0 && val->width)
		{
			val->buf[val->tmpi] = '0';
			val->buf[val->tmpi + 1] = 'x';
		}
		else
		{
			ns[i] = '0';
			i++;
			ns[i] = 'x';
			i++;
		}
	}
	if (val->flaghasj && val->specifier == 'X')
	{
		if (val->precis < 0 && val->width)
		{
			val->buf[val->tmpi] = '0';
			val->buf[val->tmpi + 1] = 'X';
		}
		else
		{
			ns[i] = '0';
			i++;
			ns[i] = 'X';
			i++;
		}
	}
	if (val->flaghasj && !val->precis && val->specifier == 'o')
		i++;
	while (tp)
	{
		ns[i] = '0';
		tp--;
		i++;
	}
	while (s[tp])
	{
		ns[i] = s[tp];
		tp++;
		i++;
	}
	ns[i] = '\0';
	free(s);
	return (ns);
}

void		ft_cpy_to_buf_lft_int_u(t_struct *val)
{
	int		b;
	int		j;
	char	*s;
	char	*ns;

	j = 0;
	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u_x(val->ud, b);
	else 
	s = ft_itoa_base_u(val->ud, b);
	ns = ft_fix_precis(val, s);
	val->bi = val->tmpi;
	while (ns[j])
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
	free(ns);
}

void		ft_cpy_to_buf_int_u(t_struct *val)
{
	int		b;
	int		i;
	int		j;
	char	*s;
	char	*ns;

	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u_x(val->ud, b);
	else 
		s = ft_itoa_base_u(val->ud, b);
	ns = ft_fix_precis(val, s);
	i = ft_strlen(ns);
	j = 0;
	val->bi -= i;
	if (val->bi < val->tmpi)
		val->bi = val->tmpi;
	while (ns[j])
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	free(ns);
}
