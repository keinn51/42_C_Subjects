
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

#include "ft_printf.h"

int field_checker(char format, va_list *ap)
{
    int result;

    result = 0;
    if (format == 'c')
        result += print_char(va_arg(*ap, int));
    else if (format == 's')
        result += print_str_null(va_arg(*ap, char *));
    else if (format == 'p')
    {
        result += write(1, "0x", 2);
        result += print_address(va_arg(*ap, unsigned long long int));
    }
    else if (format == 'i' || format == 'd')
        result += print_itoa(ft_itoa(va_arg(*ap, int)));
    else if (format == 'u')
        result += print_uint(va_arg(*ap, unsigned int));
    else if (format == 'x')
        result += print_hex(va_arg(*ap, unsigned int), 1);
    else if (format == 'X')
        result += print_hex(va_arg(*ap, unsigned int), 2);
    else if (format == '%')
		result += (int)write(1, "%", 1);
    return (result);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int result;

    va_start(ap, format);
    i = 0;
    result = 0;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
            result += write(1, &format[i], 1);
        else if (format[i] == '%')
        {
            if (format[i + 1])
                result += field_checker(format[(i++) + 1], &ap);
        }
        i++;
    }
    va_end(ap);
    return (result);
}
