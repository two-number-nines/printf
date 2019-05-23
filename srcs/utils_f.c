/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:04:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 15:53:50 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void	ft_comb_part_helper(char **ns, int i, int t)
{
	if ((*ns)[i] >= '5' || ((*ns)[i - 1] >= 5 && (*ns)[i] != '0'))
	{
		i--;
		if ((*ns)[i] >= '5')
		{
			while ((*ns)[i] == '9')
			{
				(*ns)[i] = '0';
				i--;
			}
			if ((*ns)[i - 1] >= '0' && (*ns)[i - 1] <= '9')
				(*ns)[i - 1] += 1;
			if ((*ns)[i - 1] == '.')
			{
				i -= 2;
				while ((*ns)[i] == '9')
				{
					(*ns)[i] = '0';
					i--;
				}
				(*ns)[i] += 1;
			}
		}
	}
	(*ns)[t] = '\0';
}

char		*ft_comb_part(t_struct *val, long long pleft, char *sr)
{
	char	*sl;
	char	*ns;
	int		i;
	int		b;
	int		t;

	i = 0;
	b = 0;
	sl = ft_itoa(pleft);
	ns = (char *)malloc(sizeof(char) * 2001);
	bzero(ns, 2001);
	while (sl[i])
	{
		ns[i] = sl[i];
		i++;
	}
	while_lp_f(val, &ns, sr, &i);
	t = i - 2;
	i--;
	ft_comb_part_helper(&ns, i, t);
	free(sl);
	return (ns);
}

char		*ft_combine_part(t_struct *val, double n, long long pleft)
{
	int			d;
	int			i;
	char		*ns;
	char		tempstr[2001];

	i = 0;
	bzero(tempstr, 2001);
	if (val->precis == -1)
		d = 8;
	else
		d = val->precis + 2;
	while (d)
	{
		if (n < 0)
			n *= -1;
		n = n * 10;
		tempstr[i] = (int)n + '0';
		n = n - (int)n;
		d--;
		i++;
	}
	ns = ft_comb_part(val, pleft, tempstr);
	return (ns);
}

void		ft_cpy_to_buf_int_f(t_struct *val)
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
	ft_while_loop(val, ns);
	free(ns);
}

void		ft_cpy_to_buf_lft_int_f(t_struct *val)
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
	ft_while_loop(val, ns);
	val->bi = val->width + val->tmpi;
	free(ns);
}
