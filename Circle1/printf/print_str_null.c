/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:50:32 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 20:50:50 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str_null(char *str)
{
    int result;

    result = 0;
    if (!str)
        str = "(null)";
    while (*str)
        result += (int)(write(1, str++, 1));
    return (result);
}