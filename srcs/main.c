/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/17 14:14:56 by vmulder       ########   odam.nl         */
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
		if (val.bi + 1 == BUFF_FULL)
			ft_clearbuff
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
	val.precis = -1;
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
	double i;
	double b;

	i = 12345.3999899999999999;
	b = 1.5;
	// printf("\nhex: %.2lf bla\n", i);
	// ft_printf("hex: %.2lf bla\n", i);
	// printf("\n");
	// printf("\n");
	// printf("\nhex: %#10.0lf bla\n", i);
	// ft_printf("hex: %#10.0lf bla\n", i);
	// printf("\n");
	// printf("\n");
	// printf("\nhex: %#-10.2lf bla\n", i);
	// ft_printf("hex: %#-10.2lf bla\n", i);
	// printf("\n");
	// printf("\n");
	// printf("\nhex: %#-10.6f bla\n", i);
	// ft_printf("hex: %#-10.6f bla\n", i);
	// printf("\n");
	// printf("\n");
	// printf("\nhex: %-10.6lf bla\n", i);
	// ft_printf("hex: %-10.6lf bla\n", i);
	// printf("\n");
	// printf("\n");
	printf("\nhex: %#10.8lf bla\n", i);
	ft_printf("hex: %#10.8lf bla\n", i);
	// printf("\n");
	// printf("\n");
	// printf("hex: %010.15xl\n", 200);
	// ft_printf("hex: %010.15xl\n", 200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %#10Xl\n", -200);
	// ft_printf("hex: %#10Xl\n", -200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %-10Xl\n", -200);
	// ft_printf("hex: %-10Xl\n", -200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %010Xl\n", 200);
	// ft_printf("hex: %010Xl\n", 200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %010.0Xl\n", 200);
	// ft_printf("hex: %010.0Xl\n", 200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %+10.5d\n", 200);
	// ft_printf("hex: %+10.5d\n", 200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %-010.5d\n", 200);
	// ft_printf("hex: %-010.5d\n", 200);
	// printf("---------------------------------------------------------------------------------\n");
	// printf("\n");
	// printf("\n");
	// printf("hex: %d\n", -200);
	// ft_printf("hex: %d\n", -200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %10d\n", -200);
	// ft_printf("hex: %10d\n", -200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %d\n", 200);
	// ft_printf("hex: %d\n", 200);
	// printf("\n");
	// printf("\n");
	// printf("hex: %-10dbla\n", 200);
	// ft_printf("hex: %-10dbla\n", 200);
	// ft_printf("hex: %.5d\n", -200);
	// ft_printf("hex: %+30.20lld\n", -100);
	return (0);
}
