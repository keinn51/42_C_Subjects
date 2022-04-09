/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:28 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 20:53:36 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(unsigned int num, int mode)
{
    int result;

    result = 0;
    if (num >= 16)
    {
        result += print_hex(num / 16, mode);
        result += print_hex(num % 16, mode);
    }
    if (num < 16)
    {
        if (num < 10)
            result += print_char(num + 48);
        else
        {
            if (mode == 1)
                result += print_char(num + 87);
            else
                result += print_char(num + 55);
        }
    }
    return (result);
}