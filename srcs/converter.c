/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 17:52:57 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 18:27:33 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_converter_c(t_struct *val, va_list *lp)
{
	if (val->width)
		put_width_buf(val);
	if (val->flagmin)
		val->buf[val->tmpi] = va_arg(*lp, int);
	else
		val->buf[val->bi - 1] = va_arg(*lp, int);
}

void	ft_converter_s(t_struct *val, va_list *lp)
{
	char	*s;
	int		i;
	int		tmp;

	i = 0;
	s = va_arg(*lp, char*);
	tmp = 0;
	if (val->width < (int)ft_strlen(s))
		tmp = ft_strlen(s);
	if (val->width)
		put_width_buf(val);
	if (val->flagmin)
		//ft_cpy_to_buf(val->buf, (&val->tmpi), &s);
	else
		//ft_cpy_to_buf(val->buf, (&val->bi - (ft_strlen(s) - tmp)), &s);
}
// cpy to buf needs to change the original buf index so it will not override some of the other stuff
// we gonna put in the buf later so probably should fix this on monday.