/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsDI.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/16 11:20:52 by vmulder       ########   odam.nl         */
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
	if (val->flagspace)
		ns[i] = ' ';
	if (val->flagplus)
		ns[i] = '+';
	if (val->d < 0)
		ns[i] = '-';
	if (val->d < 0 && val->precis)
		tp++;
	if (val->flagspace || val->flagplus || val->d < 0)
		i++;
	if (val->d == 0 && val->precis == 0)
	{
		ns[i] = '\0';
		return (ns);
	}
	while (tp)
	{
		ns[i] = '0';
		tp--;
		i++;
	}
	while (s[tp])
	{
		if (s[tp] == '-')
			tp++;
		ns[i] = s[tp];
		tp++;
		i++;
	}
	ns[i] = '\0';
	free(s);
	return (ns);
}

void	ft_cpy_to_buf_lft_int(t_struct *val)
{
	char *s;
	char *ns;
	int j;

	j = 0;
	s = ft_itoa(val->d);
	ns = ft_fix_precis(val, s);
	val->bi = val->tmpi;
	while (ns[j])
	{
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
	free(ns);
}

void	ft_cpy_to_buf_int(t_struct *val)
{
	int		i;
	int		j;
	char	*s;
	char	*ns;
	
	s = ft_itoa(val->d);
	ns = ft_fix_precis(val, s);
	i = ft_strlen(ns);
	j = 0;
	val->bi -= i;
	if (val->bi < val->tmpi)
		val->bi = val->tmpi;
	while (ns[j])
	{
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
	free(ns);
}

int		ft_supersayenbased(t_struct *val)
{
	if (val->fmt[val->i] == 'o')
		return (8);
	else if (val->fmt[val->i] == 'x' || val->fmt[val->i] == 'X')
		return (16);
	return (10);
}
