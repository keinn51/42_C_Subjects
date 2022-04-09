/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:52:35 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 20:52:46 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_address(unsigned long long int num)
{
    int result;

    result = 0;
    if (num >= 16)
    {
        result += print_address(num / 16);
        result += print_address(num % 16);
    }
    if (num < 16)
    {
        if (num < 10)
            result += print_char(num + 48);
        else
            result += print_char(num + 87);
    }
    return (result);
}