/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:05:51 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/27 23:24:11 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

char	*ft_strdup_before_newline(char *str)
{
	size_t	len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		print_err("Malloc Error\n");
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy_before_newline(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len != 0)
	{
		while (i < (len - 1) && src[i] != '\0' && src[i] != '\n')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin_before_newline(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len + 1);
	if (!(new_mem))
		print_err("Malloc Error\n");
	ft_strlcpy_before_newline(new_mem, s1, s1_len + 1);
	ft_strlcpy_before_newline(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (new_mem);
}
