/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 13:02:05 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 13:41:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base(int c, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *str, int base)
{
	int i;
	int ret;
	int	min_or_pos;

	i = 0;
	ret = 0;
	min_or_pos = 1;
	while (str[i] <= 32 && str[i] != '\e' && str[i] != '\0')
		i++;
	if (str[i] == '-')
		min_or_pos = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_base(str[i], base) != -1)
	{
		ret = ret * base + ft_base(str[i], base);
		i++;
	}
	return (ret * min_or_pos);
}
