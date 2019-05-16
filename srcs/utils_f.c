/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:04:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/16 19:36:26 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"
/*
static char		*ft_algo(char *nstring, int i, long long min, int p)
{
	while (min >= 10)
	{
		nstring[i] = (char)(min % 10 + '0');
		min = min / 10;
		i++;
	}
	nstring[i++] = (char)(min + '0');
	if (p < 0)
		nstring[i++] = '-';
	nstring[i] = '\0';
	ft_strrev(nstring);
	return (nstring);
}

char			*ft_itoa(float n)
{
	float		min;
	int			p;
	int			i;
	char		*nstring;

	min = n;
	if (!(nstring = (char *)malloc(sizeof(char) * ft_getdigits(n) + 1)))
		return (NULL);
	i = 0;
	p = 0;
	if (n < 0)
	{
		min = min * -1;
		p = -1;
	}
	ft_algo(nstring, i, min, p);
	return (nstring);
}
*/
/*
static void	ft_cpy_to_buf_int_if(t_struct *val, int i)
{
	if (val->flagplus && val->f >= 0)
	{
		i++;
		val->bi -= i;
		if (val->flagnull)
			val->buf[val->tmpi] = '+';
		else
			val->buf[val->bi] = '+';
		val->bi++;
	}
	else
		val->bi -= i;
}
*/
char	*ft_comb_part(t_struct *val, long long pleft, long long pright)
{
	char *sl;
	char *sr;
	char *ns;
	int i;
	int b;
	
	i = 0;
	b = 0;
	sr = ft_itoa(pright);
	sl = ft_itoa(pleft);
	ns = (char *)malloc(sizeof(char) * 100);
	printf("this is the combined string: %s\n", ns);
	while(sl[i])
	{
		ns[i] = sl[i];
		i++;
	}
	if (sr[0] != '0' || val->precis)
	{
		ns[i] = '.';
		i++;
		while (val->t)
		{
			ns[i] = '0';
			val->t--;
			i++;
		}
		while (sr[b] && sr[0] != '0')
		{
			ns[i] = sr[b];
			i++;
			b++;
		}
	}
	ns[i] = '\0';
	return (ns);
}

char *ft_combine_part(t_struct *val, float n, long long pleft)
{
	int			d;
	long long	pright;
	char *ns;

	if (val->precis == -1)
		d = 6;
	else
		d = val->precis;
	while (d)
	{
		n = n * 10;
		d--;
		if (n < 1)
			val->t++;
	}
	if (n - (long long)n > 0.5)
		n += 1;
	pright = (long long)n;
	ns = ft_comb_part(val, pleft, pright);
	printf("after the conversion: %f\n", n);
	printf("this is my after .: %lld\n", pright);
	printf("this is how many zeros: %d\n", val->t);
	printf("this is my ns string: %s\n", ns);
	return (ns);
}

void	ft_cpy_to_buf_int_f(t_struct *val)
{
	long long	pleft;
	float		leftover;
	
	pleft = (long long)val->f;
	//sl = ft_itoa(pleft);
	leftover = val->f - (float)pleft;
	// printf("this is lpart: %lld\n", pleft);
	// printf("this is rpart: %f\n", leftover);
	ft_combine_part(val, leftover, pleft);
	//j = 0;
	//ft_cpy_to_buf_int_if(val, i);
	//while (s[j])
//	{
//		val->buf[val->bi] = s[j];
//		val->bi++;
//		j++;
//	}
}
/*
void	ft_cpy_to_buf_lft_int_f(t_struct *val)
{
	int		j;
	char	*s;

	s = NULL;
	j = 0;
	//s = ftoa(val->f, s, 4);
	val->bi = val->tmpi;
	if (val->flagplus && val->f >= 0)
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
*/