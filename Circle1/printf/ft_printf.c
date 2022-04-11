/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:04:04 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/10 20:46:37 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	field_checker(char format, va_list *ap)
{
	if (format == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (format == 's')
		return (print_str_null(va_arg(*ap, char *)));
	else if (format == 'p')
		return (print_address(va_arg(*ap, void *)));
	else if (format == 'i' || format == 'd')
		return (print_itoa(ft_itoa(va_arg(*ap, int))));
	else if (format == 'u')
		return (print_uint(va_arg(*ap, unsigned int)));
	else if (format == 'x')
		return (print_hex(va_arg(*ap, unsigned int), 1));
	else if (format == 'X')
		return (print_hex(va_arg(*ap, unsigned int), 2));
	else if (format == '%')
		return ((int)write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		result;

	va_start(ap, format);
	i = 0;
	result = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			result += (int)write(1, &format[i], 1);
		else if (format[i] == '%')
			if (format[i + 1])
				result += field_checker(format[(i++) + 1], &ap);
		i++;
	}
	va_end(ap);
	return (result);
}
