/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_u_x.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 14:23:52 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/05 14:56:13 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_power(int n, int po)
{
	if (po == 0)
		return (1);
	return (n * ft_power(n, po - 1));
}

char						*ft_itoa_base_u_x(unsigned long long val, int ba)
{
	unsigned long long	nb;
	int					length;
	char				*result;
	long long			i;

	nb = val;
	length = 1;
	while (ft_power(ba, length) <= nb)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 2));
	i = 0;
	while (i < length)
	{
		if (ba <= 10 || (ba > 10 && (nb % ba) < 10))
			result[i] = (nb % ba) + 48;
		else
			result[i] = (nb % ba) - 10 + 65;
		nb /= ba;
		i++;
	}
	result[i] = '\0';
	return (ft_strrev(result));
}
