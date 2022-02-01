/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:24:55 by kyungsle          #+#    #+#             */
/*   Updated: 2022/02/01 13:46:49 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (!c)
		return (((char *)str + i));
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dst;

	dst = (char *)malloc(n + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *)malloc(len_s1 + len_s2 + 1);
	if (!dst)
		return (NULL);
	while (*s1)
		*dst++ = *s1++;
	while (*s2)
		*dst++ = *s2++;
	*dst = '\0';
	return (dst - len_s1 - len_s2);
}

void	fd_lst_clear(t_list **fd_lst, t_list *curr_lst)
{
	t_list	*tmp;

	if (!fd_lst || !(*fd_lst))
		return ;
	if (*fd_lst == curr_lst)
	{
		*fd_lst = curr_lst->next;
		free(curr_lst->content);
		free(curr_lst);
		return ;
	}
	tmp = *fd_lst;
	while (tmp && (tmp->next != curr_lst))
		tmp = tmp->next;
	tmp->next = curr_lst->next;
	free(curr_lst->content);
	free(curr_lst);
}
