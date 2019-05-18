/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/18 19:55:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	arghandeler(t_struct *val, va_list *lp)
{
	if (ft_checkperc(val))
		return ;
	ft_checkflags(val);
	ft_checkwidth(val, lp);
	ft_checkprecision(val, lp);
	ft_checklenmod(val);
	ft_checkspecifier(val, lp);
}

void	ft_strloop(t_struct *val, va_list *lp)
{
	while (val->fmt && val->fmt[val->i])
	{
		if (val->bi == BUFF_FULL)
			ft_clearbuf(val);
		if (val->fmt[val->i] == '%')
		{
			val->i++;
			arghandeler(val, lp);
			reset_flags(val);
			val->bi = (int)ft_strlen(val->buf);
		}
		val->buf[val->bi] = val->fmt[val->i];
		val->i++;
		val->bi++;
	}
	ft_clearbuf(val);
}

int		ft_initializer(const char *format, va_list *lp)
{
	t_struct val;

	ft_bzero(&val, sizeof(t_struct));
	ft_bzero(val.buf, BUFF_FULL);
	val.fmt = format;
	val.precis = -1;
	ft_strloop(&val, lp);
	return (val.ret);
}

int		ft_printf(const char *format, ...)
{
	va_list lp;
	int		ret;

	va_start(lp, format);
	ret = ft_initializer(format, &lp);
	va_end(lp);
	return (ret);
}

	int		main(void)
{
	ft_printf("@moulitest: %5.x %5.0x", 0, 0);
	printf("\n");
	printf("@moulitest: %5.x %5.0x", 0, 0);
	return 0;
}
