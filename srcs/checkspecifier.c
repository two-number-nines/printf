/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkspecifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:43:00 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/25 15:53:13 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkspecifier(t_struct *val)
{
	if (val->fmt[val->i] == 'c')
	{
		val->i++;
	}
}
