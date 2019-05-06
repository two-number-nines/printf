/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/06 16:11:12 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	arghandeler(t_struct *val, va_list *lp)
{
	ft_checkflags(val);
	ft_checkwidth(val, lp);
	ft_checkprecision(val, lp);
	ft_checklenmod(val);
	ft_checkspecifier(val, lp);
}

void	ft_strloop(t_struct val, va_list *lp)
{
	while (val.fmt && val.fmt[val.i])
	{
		//if (val.bi + 1 == BUFF_FULL)
			//ft_clearbuff
		if (val.fmt[val.i] == '%')
		{
			val.i++;
			arghandeler(&val, lp);
			reset_flags(&val);
			val.bi = (int)strlen(val.buf);
		}
		val.buf[val.bi] = val.fmt[val.i];
		val.i++;
		val.bi++;
	}
	printf("%s", val.buf);
}

void	ft_initializer(const char *format, va_list *lp)
{
	t_struct val;

	ft_bzero(&val, sizeof(t_struct));
	ft_bzero(val.buf, BUFF_FULL);
	val.fmt = format;
	ft_strloop(val, lp);
}

int		ft_printf(const char *format, ...)
{
	va_list lp;

	va_start(lp, format);
	ft_initializer(format, &lp);
	va_end(lp);
	return (1);
}

int		main(void)
{
	int *i;

	i = 0;
	//long long d = -9223372036854775806;
	//printf("%lld\n", -200);
	printf("hex: %+30d hexcapital: %+30d\n", -200, -200);
	ft_printf("hex: %+30d hexcapital: %+30d\n", -100, -200);
	//ft_printf("hex: %+30.20lld\n", -100);
	return (0);
}
