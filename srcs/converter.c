/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 17:52:57 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/30 11:42:21 by vmulder       ########   odam.nl         */
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
	if (val->width)
		put_width_buf(val);
	if ((int)ft_strlen(s) >= val->width)
		tmp = ft_strlen(s);
	if (val->flagmin || tmp)
		ft_cpy_to_buf_lft(val, s);
	else
		ft_cpy_to_buf(val, s);
}

void	ft_converter_p(t_struct *val, va_list *lp)
{
	long long	p;
	int			i;
	int			tmp;

	i = 0;
	p = va_arg(*lp, long long);
	printf("this is s: %lld\n", p);
	tmp = 0;
	long_to_a_string(p);
	if (val->width)
		put_width_buf(val);
//	if ((int)ft_strlen(s) >= val->width)
//		tmp = ft_strlen(s);
//	if (val->flagmin || tmp)
//		ft_cpy_to_buf_lft(val, s);
//	else
//		ft_cpy_to_buf(val, s);
}
