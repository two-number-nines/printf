/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/24 17:07:38 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	arghandeler(t_struct *val)
{
	ft_checkflags(val);
	ft_checkwidth(val);
}

void	ft_strloop(t_struct val)
{
	while (val.fmt && val.fmt[val.i])
	{
		
 		if (val.fmt[val.i] == '%')
 			arghandeler(&val);
		else
			val.buf[val.i] = val.fmt[val.i];
		val.i++;
	}
}

void	ft_initializer(const char *format)
{
	t_struct val;
	val.flags = 0;
	val.i = 0;
	val.fmt = format;
	ft_strloop(val);
}

int		ft_printf(const char *format, ...)
{
	va_list lp;
	va_start(lp, format);
	ft_initializer(format);
	va_end(lp);
	return (1);
}

int		main(void)
{
	//ft_printf("my printf: c\n", ft_atoi("10"), ft_atoi("20"), ft_atoi("30"));
	printf("max width: %0214748364d", 9);
	//printf("real printf: c\n");
	return (0);
}