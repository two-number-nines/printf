/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_u.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:20:48 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/05 14:56:03 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_power(int n, int po)
{
	if (po == 0)
		return (1);
	return (n * ft_power(n, po - 1));
}

char						*ft_itoa_base_u(unsigned long long value, int base)
{
	unsigned long long	nb;
	int					length;
	char				*result;
	long long			i;

	nb = value;
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
	result[i] = '\0';
	return (ft_strrev(result));
}
