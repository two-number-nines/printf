/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/06 11:04:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/16 16:24:07 by vmulder       ########   odam.nl         */
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
long long ft_right_part(t_struct *val, float n)
{
	int d;
	long long r;

	if (val->precis == -1)
		d = 6;
	else
		d = val->precis;
	
	while (d)
	{
		n = n * 10;
		d--;
	}
	if (n - (long long)n > 0.5)
		n += 1;
	r = n;
	printf("after the conversion: %f\n", n);
	return (r);
}

void	ft_cpy_to_buf_int_f(t_struct *val)
{
	long long	leftp;
	float		rightp;
	int			i;
	//int			j;
	char		*s;
	
	leftp = (long long)val->f;
	s = ft_itoa(leftp);
	rightp = val->f - (float)leftp;
	i = ft_strlen(s);
	printf("this is lpart: %lld\n", leftp);
	printf("this is rpart: %f\n", rightp);
	ft_right_part(val, rightp);
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