/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 15:42:55 by vmulder        #+#    #+#                */
/*   Updated: 2019/04/23 15:57:13 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	csphaneler(const char *format, char c)
{
	(void)format;
	if (c == 'c')
	{
		printf("hoi");
	}
	else if (c == 's')
	{
		printf("hoi");
	}
	else if (c == 'p')
	{
		printf("hoi");
	}
}

void	arghandeler(const char *format, char c)
{
	(void)format;
	if (c == 'c' || c == 's' || c == 'p')
		csphaneler(format, c);
}

void	ft_strloop(const char *format, va_list listpointer)
{
	int i;
	(void)listpointer;
	char buf[1000] = "";

	i = 0;
	while (format && format[i])
	{
		
 		if (format[i] == '%')
 			arghandeler(format, format[i + 1]);
		else
			buf[j] = format[i];
		i++;
		j++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list listpointer;
	va_start(listpointer, format);
	ft_strloop(format, listpointer);
	va_end(listpointer);
	return (1);
}

int		main(void)
{
	//ft_printf("my printf: c\n", ft_atoi("10"), ft_atoi("20"), ft_atoi("30"));
	ft_printf("my printf: %c\n");
	//printf("real printf: c\n");
	return (0);
}