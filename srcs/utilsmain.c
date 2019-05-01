/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilsmain.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 12:11:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/01 13:57:18 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	reset_flags(t_struct *val)
{
	val->flagmin = 0;
	val->flagplus = 0;
	val->flagspace = 0;
	val->flaghasj = 0;
	val->flagnull = 0;
	val->width = 0;
	val->precis = 0;
	val->length = 0;
	val->hh = 0;
	val->h = 0;
	val->l = 0;
	val->ll = 0;
	val->L = 0;
}

void	clear_buf(t_struct *val)
{
	int i;
	//i should be something in the struct
	i = ft_strlen(val->buf);
	ft_putstr(val->buf);
	val->bi = 0;
	ft_bzero(val->buf, BUFF_FULL);
}