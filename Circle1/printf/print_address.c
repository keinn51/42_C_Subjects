/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:52:35 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/10 16:59:34 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_recursive(unsigned long long int num)
{
	int	result;

	result = 0;
	if (num >= 16)
	{
		result += print_hex_recursive(num / 16);
		result += print_hex_recursive(num % 16);
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

int	print_address(void *ptr)
{
	unsigned long long int	num;
	int						result;

	result = 0;
	num = (unsigned long long int)ptr;
	result += (int)write(1, "0x", 2);
	result += print_hex_recursive(num);
	return (result);
}
