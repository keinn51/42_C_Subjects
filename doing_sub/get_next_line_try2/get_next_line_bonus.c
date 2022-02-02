/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:25:01 by kyungsle          #+#    #+#             */
/*   Updated: 2022/02/02 13:55:55 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	set_result(t_list *curr_lst, char *nptr, char **res)
{
	char	*temp;

	if (nptr)
	{
		*res = ft_strndup(curr_lst->content, nptr - (curr_lst->content) + 1);
		temp = ft_strndup(nptr + 1, ft_strlen(nptr + 1));
		if (!*res || !temp)
			return (-1);
		free(curr_lst->content);
		curr_lst->content = temp;
		return (1);
	}
	else
	{
		if (curr_lst->content && *(curr_lst->content) == '\0')
			*res = NULL;
		else
		{
			*res = ft_strndup(curr_lst->content, ft_strlen(curr_lst->content));
			temp = ft_strndup("", 0);
			free(curr_lst->content);
			curr_lst->content = temp;
		}
		return (0);
	}
}

int	read_file(t_list *curr_lst, char *buff, char **res)
{
	char		*nptr;
	char		*temp;
	ssize_t		len;

	while (1)
	{
		nptr = ft_strchr(curr_lst->content, '\n');
		if (nptr)
			break ;
		len = read(curr_lst->fd, buff, BUFFER_SIZE);
		if (len == -1)
			return (-1);
		if (len == 0)
			break ;
		buff[len] = '\0';
		temp = ft_strjoin(curr_lst->content, buff);
		if (!temp)
			return (-1);
		free(curr_lst->content);
		curr_lst->content = temp;
	}
	return (set_result(curr_lst, nptr, res));
}

t_list	*make_newlst(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->content = ft_strndup("", 0);
	new->next = NULL;
	return (new);
}

t_list	*set_curr_lst(t_list **fd_lst, int fd)
{
	t_list	*curr_lst;

	if (!fd_lst)
		return (NULL);
	if (!(*fd_lst))
	{
		curr_lst = make_newlst(fd);
		*fd_lst = curr_lst;
		return (curr_lst);
	}
	else
		curr_lst = *fd_lst;
	while (curr_lst && (curr_lst->fd != fd))
		curr_lst = curr_lst->next;
	if (curr_lst)
		return (curr_lst);
	curr_lst = make_newlst(fd);
	curr_lst->next = *fd_lst;
	*fd_lst = curr_lst;
	return (curr_lst);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_lst;
	t_list			*curr_lst;
	char			*buff;
	char			*res;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr_lst = set_curr_lst(&fd_lst, fd);
	if (!curr_lst)
		return (NULL);
	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	res = NULL;
	status = read_file(curr_lst, buff, &res);
	free(buff);
	if (status == 0 || status == -1)
		fd_lst_clear(&fd_lst, curr_lst);
	if (status == -1)
		return (NULL);
	return (res);
}
