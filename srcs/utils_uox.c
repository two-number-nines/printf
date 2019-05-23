/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_uox.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:56:03 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 14:28:35 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static int	ft_fix_precis_if(t_struct *val, char **ns, int *i)
{
	(*i) = 0;
	if (val->ud == 0 && val->precis <= 0 && val->flaghasj == 0)
	{
		if (val->precis < 0)
			(*ns)[(*i)] = '0';
		return (1);
	}
	if (val->ud == 0 && val->precis == 0 && (val->specifier == 'x' \
		|| val->specifier == 'X'))
		return (1);
	if (val->flaghasj && val->specifier == 'o' && val->ud != 0)
	{
		(*ns)[(*i)] = '0';
		(*i)++;
	}
	return (0);
}

static void	ft_fix_precis_iftwo(t_struct *val, char **ns, int *i)
{
	if (val->flaghasj && val->specifier == 'x' && val->ud != 0)
	{
		if (val->flagnull)
			val->buf[val->tmpi + 1] = 'x';
		else
		{
			(*ns)[0] = '0';
			(*ns)[1] = 'x';
			(*i) = 2;
		}
	}
	if (val->flaghasj && val->specifier == 'X' && val->ud != 0)
	{
		if (val->flagnull)
			val->buf[val->tmpi + 1] = 'X';
		else
		{
			(*ns)[0] = '0';
			(*ns)[1] = 'X';
			(*i) = 2;
		}
	}
	if (val->flaghasj && !val->precis && val->specifier == 'o' && val->ud != 0)
		(*i)++;
}

static char	*ft_fix_precis(t_struct *val, char *s)
{
	char	*ns;
	int		i;
	int		tp;

	tp = 0;
	if (val->precis > (int)ft_strlen(s))
		tp = val->precis - ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * tp + ft_strlen(s) + 1);
	bzero(ns, tp + ft_strlen(s) + 1);
	if (ft_fix_precis_if(val, &ns, &i))
		return (ns);
	ft_fix_precis_iftwo(val, &ns, &i);
	while_loop_pr(&tp, &ns, &i, &s);
	ns[i] = '\0';
	free(s);
	return (ns);
}

void		ft_cpy_to_buf_lft_int_u(t_struct *val)
{
	int		b;
	char	*s;
	char	*ns;

	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u(val->ud, b, 1);
	else
		s = ft_itoa_base_u(val->ud, b, 0);
	ns = ft_fix_precis(val, s);
	val->bi = val->tmpi;
	ft_while_loop(val, ns);
	val->bi = val->width + val->tmpi;
	free(ns);
}

void		ft_cpy_to_buf_int_u(t_struct *val)
{
	int		b;
	int		i;
	char	*s;
	char	*ns;

	b = ft_supersayenbased(val);
	if (val->specifier == 'X')
		s = ft_itoa_base_u(val->ud, b, 1);
	else
		s = ft_itoa_base_u(val->ud, b, 0);
	ns = ft_fix_precis(val, s);
	i = ft_strlen(ns);
	val->bi -= i;
	if (val->bi < val->tmpi)
		val->bi = val->tmpi;
	ft_while_loop(val, ns);
	free(ns);
}
