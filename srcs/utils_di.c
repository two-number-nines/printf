/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_di.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 18:25:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 14:28:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static char		*ft_fix_helper(t_struct *val, char *s)
{
	char	*ns;

	ns = (char *)malloc(sizeof(char) * val->precis + ft_strlen(s) + 3);
	ft_bzero(ns, (size_t)(val->precis + ft_strlen(s) + 3));
	if (val->flagnull && val->precis < 0 && val->width)
	{
		if (val->flagspace)
			val->buf[val->tmpi] = ' ';
		if (val->flagplus)
			val->buf[val->tmpi] = '+';
		if (val->d < 0)
			val->buf[val->tmpi] = '-';
	}
	else
	{
		if (val->flagspace)
			ns[0] = ' ';
		if (val->flagplus)
			ns[0] = '+';
		if (val->d < 0)
			ns[0] = '-';
	}
	return (ns);
}

static char		*ft_fix_precis(t_struct *val, char *s)
{
	char	*ns;
	int		i;
	int		tp;

	i = 0;
	tp = 0;
	if (val->precis > (int)ft_strlen(s))
		tp = val->precis - ft_strlen(s);
	ns = ft_fix_helper(val, s);
	if (val->d < 0 && val->precis && val->precis != -1)
	{
		if (val->precis >= (int)ft_strlen(s))
			tp++;
	}
	if ((val->flagspace || val->flagplus || val->d < 0) && (!val->flagnull || \
		(val->flagnull && val->precis >= 0) || (val->flagnull && !val->width)))
		i++;
	if (val->d == 0 && val->precis == 0)
	{
		ns[i] = '\0';
		return (ns);
	}
	while_lp_pr_neg(&tp, &ns, &i, &s);
	free(s);
	return (ns);
}

void			ft_cpy_to_buf_lft_int(t_struct *val)
{
	char	*s;
	char	*ns;
	int		j;

	j = 0;
	if (val->d == (double)-9223372036854775808.0f)
	{
		s = (char *)malloc(sizeof(char) * 21);
		ft_bzero(s, 21);
		ft_strcat(s, "-9223372036854775808");
	}
	else
		s = ft_itoa(val->d);
	ns = ft_fix_precis(val, s);
	val->bi = val->tmpi;
	ft_while_loop(val, ns);
	val->bi = val->width + val->tmpi;
	free(ns);
}

void			ft_cpy_to_buf_int(t_struct *val)
{
	int		i;
	int		j;
	char	*s;
	char	*ns;

	j = 0;
	if (val->d == (double)-9223372036854775808.0f)
	{
		s = (char *)malloc(sizeof(char) * 21);
		ft_bzero(s, 21);
		ft_strcat(s, "-9223372036854775808");
	}
	else
		s = ft_itoa(val->d);
	ns = ft_fix_precis(val, s);
	i = ft_strlen(ns);
	val->bi -= i;
	if (val->bi < val->tmpi)
		val->bi = val->tmpi;
	ft_while_loop(val, ns);
	free(ns);
}

int				ft_supersayenbased(t_struct *val)
{
	if (val->fmt[val->i] == 'o')
		return (8);
	else if (val->fmt[val->i] == 'x' || val->fmt[val->i] == 'X')
		return (16);
	return (10);
}
