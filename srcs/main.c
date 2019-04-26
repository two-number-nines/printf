/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/26 18:06:23 by vmulder       ########   odam.nl         */
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
	ft_printf("my printf: %5skoek\n", "abcdefg");
	printf("real printf: %5skoek\n", "abcdefg");
	//ft_printf("my printf: %00ckoek\n", 'c');
	//printf("real printf: %00ckoek\n", 'c');
	//printf("max width: %005d", 9);
	//printf("real printf: c\n");
	return (0);
}
