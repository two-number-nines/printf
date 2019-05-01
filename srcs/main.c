/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/01 15:01:45 by vmulder       ########   odam.nl         */
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
	printf("%u\n", 2147483649);
	//printf("real str: %20sk ptr: %p chr: %-10c prc: %% int: %-+10d oct: %o uns dec: %u\n", "bla", &i, 'A', 54, 11, 2147483649);
	//ft_printf("my   str: %20sk ptr: %p chr: %-10c prc: %% int: %-+10d oct: %o uns dec: %u\n", "bla", &i, 'A', 54, 11, 2147483649);
	//ft_printf("my printf: %00ckoek\n", 'c');
	//printf("real printf: %00ckoek\n", 'c');
	//printf("max width: %005d", 9);
	//printf("real printf: c\n");
	return (0);
}
