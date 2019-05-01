/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 11:49:10 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 18:25:10 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"
//s is gonna leak probably
char	*long_to_a_string(long long l)
{
	char	*s;
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * 3);
	ft_bzero(s1, 3);
	ft_strcat(s1, "0x");
	s = ft_itoa_base(l, 16);
	s1 = ft_strcat(s1, s);
	return (s1);
}

void	put_width_buf(t_struct *val)
{
	int i;

	i = val->width;
	while (i)
	{
		if (val->flagnull)
			val->buf[val->bi] = '0';
		else
			val->buf[val->bi] = ' ';
		i--;
		val->bi++;
	}
}

void	ft_cpy_to_buf(t_struct *val, char *s)
{
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	val->bi -= i;
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
}

void	ft_cpy_to_buf_lft(t_struct *val, char *s)
{
	int j;

	j = 0;
	val->bi = val->tmpi;
	while (s[j])
	{
		val->buf[val->bi] = s[j];
		val->bi++;
		j++;
	}
	val->bi = val->width + val->tmpi;
}
