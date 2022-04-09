/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:53:04 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 20:53:10 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_uint(unsigned int num)
{
    int result;

    result = 0;
    if (num >= 10)
    {
        result += print_uint(num / 10);
        result += print_uint(num % 10);
    }
    else if (num < 10)
        result += print_char(num + 48);
    return (result);
}