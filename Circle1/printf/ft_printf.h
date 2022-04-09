/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:21:22 by kyungsle          #+#    #+#             */
/*   Updated: 2022/04/09 21:46:37 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int print_char(char c);
char *ft_itoa(int n);
int print_str_null(char *str);
int print_itoa(char *str);
int print_address(unsigned long long int num);
int print_uint(unsigned int num);
int print_hex(unsigned int num, int mode);
int field_checker(char format, va_list *ap);
int ft_printf(const char *format, ...);

#endif