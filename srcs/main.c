/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/25 15:21:23 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	arghandeler(t_struct *val, va_list lp)
{
	printf("arghandljoe\n");
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
		
 		if (val.fmt[val.i] == '%')
		{
			//printf("ifinstrloopjoe\n");
			val.i++;
			printf("this char im sending: %c\n", val.fmt[val.i]);
 			arghandeler(&val, lp);
		}
		else
			val.buf[val.i] = val.fmt[val.i];
		val.i++;
	}
}

void	ft_initializer(const char *format, va_list lp)
{
	t_struct val;
	val.flags = 0;
	val.i = 0;
	val.fmt = format;
	//printf("initjoe\n");
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
	ft_printf("my printf: %-500.400L\n");
	printf("%*d", 5, 5);
	//printf("max width: %005d", 9);
	//printf("real printf: c\n");
	return (0);
}