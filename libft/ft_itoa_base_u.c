/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_u.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:20:48 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/18 16:18:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_helper(unsigned long long *num, int base, int *i, int *count)
{
	char				*new;
	unsigned long long	tmp;
	int					len;

	len = 0;
	tmp = *num;
	while (tmp >= (unsigned long long)base)
	{
		tmp /= (unsigned long long)base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char		*ft_itoa_base_u(unsigned long long n, int base, int q)
{
	char				*base_d;
	char				*new;
	unsigned long long	num;
	int					i;
	int					count;

	i = 0;
	count = 0;
	num = n;
	if (q)
		base_d = ft_strdup("0123456789ABCDEF");
	else
		base_d = ft_strdup("0123456789abcdef");
	new = itoa_helper(&num, base, &i, &count);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= (unsigned long long)base)
	{
		new[--count] = base_d[num % (unsigned long long)base];
		num /= base;
	}
	new[i] = base_d[num % (unsigned long long)base];
	ft_strdel(&base_d);
	return (new);
}
