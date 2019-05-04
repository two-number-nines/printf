/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/04 17:43:25 by vmulder       ########   odam.nl         */
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

	val.flagmin = 0;
	val.flagplus = 0;
	val.flagspace = 0;
	val.flaghasj = 0;
	val.flagnull = 0;
	val.i = 0;
	val.bi = 0;
	val.fmt = format;
	val.width = 0;
	val.precis = 0;
	val.length = 0;
	val.hh = 0;
	val.h = 0;
	val.l = 0;
	val.ll = 0;
	val.L = 0;
	ft_bzero(val.buf, BUFF_FULL);
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
	//printf("%u\n", (unsigned int)2147483648);
	printf("hex: %10o oct: %-20o\n", 501234, 200);
	ft_printf("hex: %10o oct: %-20o\n", 501234, 200);
	return (0);
}

//need to fix the flags cause it segfaults,  floats need to be done annd why cant i give %u a higher int