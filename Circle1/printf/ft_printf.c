
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

int printf_putstr_null(char *str)
{
    int result;

    result = 0;
    if (!str)
        str = "(null)";
    while (*str)
        result += (int)(write(1, str++, 1));
    return (result);
}

int printf_putchar(char c)
{
    int result;

    result = 0;
    result += (int)(write(1, &c, 1));
    return (result);
}

int print_adr(unsigned long int nb)
{
    int len;

    len = 0;
    if (nb >= 16)
    {
        len += print_adr(nb / 16);
        len += print_adr(nb % 16);
    }
    if (nb < 16)
    {
        if (nb < 10)
            len += printf_putchar(nb + 48);
        else
            len += printf_putchar(nb + 87);
    }
    return (len);
}

int field_checker(char format, va_list *ap)
{
    int result;

    result = 0;
    if (format == 'c')
        result += printf_putchar(va_arg(*ap, int));
    else if (format == 's')
        result += printf_putstr_null(va_arg(*ap, char *));
    else if (format == 'p')
    {
        result += write(1, "0x", 2);
        result += print_adr(va_arg(*ap, unsigned long int));
    }
    else if (format == 'i' || format == 'd')
        result += printf_putstr_null(ft_itoa(va_arg(*ap, int)));
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

int main()
{
}