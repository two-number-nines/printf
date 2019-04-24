/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/24 11:49:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_checkflags(t_struct val)
{
	
}

void	arghandeler(t_struct val)
{
	ft_checkflags(val);
}

void	ft_strloop(t_struct val)
{
	while (val.format && val.format[i])
	{
		
 		if (format[i] == '%')
 			arghandeler(val);
		else
			val.buf[val.i] = val.format[val.i];
		i++;
	}
}

void	ft_initializer(const char *format, va_list listpointer)
{
	t_struct val;
	val.i = 0;
	val.listpointer = listpointer;
	val.format = format;
}

int		ft_printf(const char *format, ...)
{
	va_list listpointer;
	va_start(listpointer, format);
	ft_initializer(format, listpointer);
	va_end(listpointer);
	return (1);
}
char		ft_test(void)
{
	return('A');
}
int		main(void)
{
	//ft_printf("my printf: c\n", ft_atoi("10"), ft_atoi("20"), ft_atoi("30"));
	printf("my printf:%c\n", ft_test());
	//printf("real printf: c\n");
	return (0);
}