/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getdigits_u.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 13:00:02 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/04 15:45:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getdigits_u(unsigned long long c)
{
	int i;

	i = 1;
	while (c >= 10)
	{
		c /= 10;
		i++;
	}
	return (i);
}
