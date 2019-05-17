/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:04:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/17 19:18:58 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*ft_comb_part(t_struct *val, long long pleft, char *sr)
{
	char *sl;
	char *ns;
	int i;
	int b;
	int t;
	
	i = 0;
	b = 0;
	sl = ft_itoa(pleft);
	ns = (char *)malloc(sizeof(char) * 100);
	while(sl[i])
	{
		ns[i] = sl[i];
		i++;
	}
	if (sr[0] != '0' || val->precis || val->flaghasj)
	{
		ns[i] = '.';
		i++;
		while (sr[b] && sr[0] != '0')
		{
			ns[i] = sr[b];
			i++;
			b++;
		}
	}
	t = i - 1;
	i--;
	if (ns[i] > '5')
	{
		while (ns[i] == '9')
		{
			ns[i] = '0';
			i--;
		}
	if (ns[i - 1] >= '0' && ns[i - 1] <= '9')
		ns[i - 1] += 1;
	if (ns[i - 1] == '.')
	{
		i -= 2;
		while (ns[i] == '9')
		{
			ns[i] = '0';
			i--;
		}
		ns[i] += 1;
	}
	}
	ns[t] = '\0';
	free(sl);
	return (ns);
}

char *ft_combine_part(t_struct *val, double n, long long pleft)
{
	int			d;
	int			i;
	char		*ns;
	char		tempstr[1000];

	i = 0;
	bzero(tempstr, 1000);
	if (val->precis == -1)
		d = 7;
	else
		d = val->precis + 1;
	while (d)
	{
		n = n * 10;
		tempstr[i] = (int)n + '0';
		n = n - (int)n;
		d--;
		i++;
	}
	ns = ft_comb_part(val, pleft, tempstr);
	return (ns);
}

void	ft_cpy_to_buf_int_f(t_struct *val)
{
	long long	pleft;
	double		leftover;
	char		*ns;
	int			j;
	
	pleft = (long long)val->f;
	leftover = val->f - (double)pleft;
	ns = ft_combine_part(val, leftover, pleft);
	j = ft_strlen(ns);
	val->bi -= j;
	if (val->bi < val->tmpi)
		val->bi = val->tmpi;
	j = 0;
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

void	ft_cpy_to_buf_lft_int_f(t_struct *val)
{
	long long	pleft;
	double		leftover;
	char		*ns;
	int			j;

	j = 0;	
	pleft = (long long)val->f;
	leftover = val->f - (double)pleft;
	ns = ft_combine_part(val, leftover, pleft);
	val->bi = val->tmpi;
	if (val->flagplus && val->f >= 0)
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = '+';
		val->bi++;
	}
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
