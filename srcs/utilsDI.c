/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsDI.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/13 12:33:06 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*remove_minus(char *s)
{
	int		i;
	int		b;
	char	*ns;

	b = strlen(s);
	ns = (char *)malloc(sizeof(char)* b + 1);
	i = 0;
	b = 0;
	while(s[i])
	{
		if (s[i] == '-')
			ns[b] = '0';
		else
			ns[b] = s[i];
		i++;
		b++;
	}
	ns[b] = '\0';
	free(s);
	return (ns);
}

void	put_precis_buf(t_struct *val)
{
	int i;

	i = val->precis;
	val->bi -= val->precis;
	while (i)
	{
		val->buf[val->bi] = '0';
		i--;
		val->bi++;
	}
}

int		ft_supersayenbased(t_struct *val)
{
	if (val->fmt[val->i] == 'o')
		return (8);
	else if (val->fmt[val->i] == 'x' || val->fmt[val->i] == 'X')
		return (16);
	return (10);
}

void	ft_cpy_to_buf_int(t_struct *val)
{
	int		i;
	int		j;
	char	*s;
	int		a;

	a = 0;
	if (val->d < 0 && val->precis > (ft_getdigits(val->d)))
	{
		val->d *= -1;
		a = 1;
	}
	s = ft_itoa(val->d);
	i = ft_strlen(s);
	j = 0;
	val->bi = val->bi - i;
	if (a || val->flagplus || val->flagspace)
	{
		if (val->width && !val->precis)
		{
			if (val->flagspace)
				val->buf[val->tmpi] = ' ';
			if (a)
				val->buf[val->tmpi] = '-';
			else if (val->flagplus)
				val->buf[val->tmpi] = '+';
		}
		else
		{
			if (val->flagspace)
			{
				val->buf[val->bi - (val->precis - i)] = ' ';
				val->buf[val->bi] = '0';
			}
			if (a)
			{
				val->buf[val->bi - (val->precis - i)] = '-';
				val->buf[val->bi] = '0';
			}
			else if (val->flagplus)
			{
				val->buf[val->bi - (val->precis - i)] = '+';
				val->buf[val->bi] = '0';
			}
		}
		val->bi++;
	}
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		j++;
		val->bi++;
	}	
	
}

void	ft_cpy_to_buf_lft_int(t_struct *val)
{
	int		j;
	char	*s;
	int		i;
	int		a;

	j = 0;
	a = 0;
	s = ft_itoa(val->d);
	i = ft_strlen(s);
	val->bi = val->tmpi;
	if (a || val->flagplus || val->flagspace)
	{
		if (val->width && !val->precis)
		{
			if (val->flagspace)
				val->buf[val->bi] = ' ';
			if (a)
				val->buf[val->bi] = '-';
			else if (val->flagplus)
				val->buf[val->bi] = '+';
		}
		else
		{
			if (val->flagspace)
			{
				val->buf[val->bi] = ' ';
				//val->buf[val->bi] = '0';
			}
			if (a)
			{
				val->buf[val->bi] = '-';
				//val->buf[val->bi] = '0';
			}
			else if (val->flagplus)
			{
				val->buf[val->bi] = '+';
				//val->buf[val->bi] = '0';
			}
		}
		val->bi++;
	}
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		j++;
		val->bi++;
	}	
	val->bi = val->width + val->tmpi;
}
