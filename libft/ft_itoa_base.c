/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:20:57 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/06 14:05:47 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_power(int n, int po)
{
	if (po == 0)
		return (1);
	return (n * ft_power(n, po - 1));
}

char				*ft_itoa_base(long long value, int base)
{
	long long	nb;
	int			length;
	char		*result;
	long long	sign;
	long long	i;

	nb = value;
	sign = 1;
	length = 1;
	while (ft_power(base, length) <= nb)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 2));
	i = 0;
	while (i < length)
	{
		if (base <= 10 || (base > 10 && (nb % base) < 10))
			result[i] = (nb % base) + 48;
		else
			result[i] = (nb % base) - 10 + 97;
		nb /= base;
		i++;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
