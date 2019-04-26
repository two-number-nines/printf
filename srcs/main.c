/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 10:37:18 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	arghandeler(t_struct *val, va_list lp)
{
	ft_checkflags(val);
	ft_checkwidth(val, lp);
	ft_checkprecision(val, lp);
	ft_checklenmod(val);
	ft_checkspecifier(val);
}

void	ft_strloop(t_struct val, va_list lp)
{
	while (val.fmt && val.fmt[val.i])
	{
		//if (val.bi + 1 == BUFF_FULL)
			//ft_clearbuff
		if (val.fmt[val.i] == '%')
		{
			val.i++;
			arghandeler(&val, lp);
		}
		else
			val.buf[val.bi] = val.fmt[val.i];
		val.i++;
		val.bi++;
	}
}

void	ft_initializer(const char *format, va_list lp)
{
	t_struct val;

	val.flags = 0;
	val.i = 0;
	val.bi = 0;
	val.fmt = format;
	ft_bzero(val.buf, BUFF_FULL);
	ft_strloop(val, lp);
}

int		ft_printf(const char *format, ...)
{
	va_list lp;

	va_start(lp, format);
	ft_initializer(format, lp);
	va_end(lp);
	return (1);
}

int		main(void)
{
	//ft_printf("my printf: %-500.400L\n");
	printf("%0.4lf\n", 3.12);
	printf("%010lf\n", 3.12);
	//printf("max width: %005d", 9);
	//printf("real printf: c\n");
	return (0);
}
