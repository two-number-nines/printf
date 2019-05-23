/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whileloops.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 13:39:48 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 14:35:50 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void		while_loop_pr(int *tp, char **ns, int *i, char **s)
{
	while ((*tp))
	{
		(*ns)[(*i)] = '0';
		(*tp)--;
		(*i)++;
	}
	while ((*s)[*tp])
	{
		(*ns)[(*i)] = (*s)[(*tp)];
		(*tp)++;
		(*i)++;
	}
}

void		while_lp_pr_neg(int *tp, char **ns, int *i, char **s)
{
	while ((*tp))
	{
		(*ns)[(*i)] = '0';
		(*tp)--;
		(*i)++;
	}
	while ((*s)[*tp])
	{
		if ((*s)[(*tp)] == '-')
			(*tp)++;
		(*ns)[(*i)] = (*s)[(*tp)];
		(*tp)++;
		(*i)++;
	}
}

void		ft_while_loop(t_struct *val, char *ns)
{
	int j;

	j = 0;
	while (ns[j])
	{
		if (val->bi + 1 == BUFF_FULL)
			ft_clearbuf(val);
		val->buf[val->bi] = ns[j];
		val->bi++;
		j++;
	}
}

void		while_lp_f(t_struct *val, char **ns, char *sr, int *i)
{
	int b;

	b = 0;
	if (sr[0] != '0' || val->precis || val->flaghasj)
	{
		(*ns)[(*i)] = '.';
		(*i)++;
		while (sr[b] && sr[0] != '0')
		{
			(*ns)[(*i)] = sr[b];
			(*i)++;
			b++;
		}
	}
}
