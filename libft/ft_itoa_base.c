/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:20:57 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/23 11:51:38 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_init(int *i, int *count, long long *n, long long *num)
{
	(*i) = 0;
	(*count) = 0;
	(*num) = (*n);
}

static char	*itoa_helper(long long *num, int base, int *i, int *count)
{
	char		*new;
	long long	tmp;
	int			len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char		*ft_itoa_base(long long n, int base, int q)
{
	char		*base_d;
	char		*new;
	long long	num;
	int			i;
	int			count;

	itoa_init(&i, &count, &n, &num);
	if (q)
		base_d = ft_strdup("0123456789ABCDEF");
	else
		base_d = ft_strdup("0123456789abcdef");
	new = itoa_helper(&num, base, &i, &count);
	if (i > 0)
	{
		new[0] = '-';
	}
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	ft_strdel(&base_d);
	return (new);
}
