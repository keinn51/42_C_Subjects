/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:40:27 by kyungsle          #+#    #+#             */
/*   Updated: 2022/03/15 21:29:43 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
// #include <stdlib.h>

int	printf_putstr_null(char *str)
{
	int	result;

	result = 0;
	if (!str)
		str = "(null)";
	while (*str)
		result += (int)(write(1, str++, 1));
	return (result);
}

int	int_putchar(char c)
{
	int result;

	result = 0;
	result += (int)(write(1, &c, 1));
	return (result);
}

int field_checker(char format, va_list *ap)
{
	int result;

	result = 0;
	if (format == 'c')
	{
		result += ft_putchar(va_arg(*ap, int));
	}
	else if(format == 's')
	{
		ft_putstr_null(va_arg(*ap, char *));
	}
	else if (format == 'i')
	{
	}

	else if
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	int result;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			result += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			result += field_checker(format[i + 1], &ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (result);
}