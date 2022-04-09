/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:51:08 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 21:46:24 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_itoa(char *str)
{
    int result;
    int i;

    result = 0;
    i = 0;
    if (!str)
        return (-1);
    while (str[i])
        result += (int)(write(1, &(str[i++]), 1));
    free(str);
    return (result);
}