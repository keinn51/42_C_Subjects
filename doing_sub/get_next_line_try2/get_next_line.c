/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:25:01 by kyungsle          #+#    #+#             */
/*   Updated: 2022/02/02 21:47:58 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	set_result(t_list *curr_ptr, char *nlptr, char **res, int eof)
{
	char	*temp;

	if (nlptr && !eof)
	{
		*res = ft_strndup(curr_ptr->content, nlptr - (curr_ptr->content) + 1);
		temp = ft_strndup(nlptr + 1, ft_strlen(nlptr + 1));
		if (!*res || !temp)
			return (-1);
		free(curr_ptr->content);
		curr_ptr->content = temp;
		return (ft_strlen(curr_ptr->content));
	}
	if (*(curr_ptr->content) == '\0')
		*res = NULL;
	else
	{
		*res = ft_strndup(curr_ptr->content, ft_strlen(curr_ptr->content));
		temp = ft_strndup("", 0);
		if (!*res || !temp)
			return (-1);
		free(curr_ptr->content);
		curr_ptr->content = temp;
	}
	return (0);
}

int	read_file(t_list *curr_ptr, char *buff, char **res)
{
	char		*nlptr;
	char		*temp;
	ssize_t		len;

	while (1)
	{
		len = read(curr_ptr->fd, buff, BUFFER_SIZE);
		if (len == -1)
			return (-1);
		if (len == 0)
			return (set_result(curr_ptr, nlptr, res, 1));
		buff[len] = '\0';
		temp = ft_strjoin(curr_ptr->content, buff);
		if (!temp)
			return (-1);
		free(curr_ptr->content);
		curr_ptr->content = temp;
		nlptr = ft_strchr(curr_ptr->content, '\n');
		if (len < BUFFER_SIZE)
			return (set_result(curr_ptr, nlptr, res, 1));
		if (nlptr)
			break ;
	}
	return (set_result(curr_ptr, nlptr, res, 0));
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
	if (!(new->content))
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	return (new);
}

t_list	*set_curr_ptr(t_list **head_ptr, int fd)
{
	t_list	*curr_ptr;

	if (!head_ptr)
		return (NULL);
	if (!(*head_ptr))
	{
		curr_ptr = make_newlst(fd);
		*head_ptr = curr_ptr;
		return (curr_ptr);
	}
	else
		curr_ptr = *head_ptr;
	while (curr_ptr && (curr_ptr->fd != fd))
		curr_ptr = curr_ptr->next;
	if (curr_ptr)
		return (curr_ptr);
	curr_ptr = make_newlst(fd);
	curr_ptr->next = *head_ptr;
	*head_ptr = curr_ptr;
	return (curr_ptr);
}

char	*get_next_line(int fd)
{
	static t_list	*head_ptr;
	t_list			*curr_ptr;
	char			*buff;
	char			*res;
	int				status;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr_ptr = set_curr_ptr(&head_ptr, fd);
	if (!curr_ptr)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	status = read_file(curr_ptr, buff, &res);
	free(buff);
	buff = NULL;
	if (status == 0 || status == -1)
		ft_lstdel(&head_ptr, curr_ptr);
	if (status == -1)
		return (NULL);
	return (res);
}

#include <fcntl.h> //have to remove!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int 	fd = open("43_with_nl", O_RDONLY);
	char 	*res;
	int     i = 0;
	
	while ((res = get_next_line(fd)))
	{
		printf ("★★★(%d) result: %s$\n", i++, res );
		free(res);
	}
	close(fd);

	// system("leaks a.out");
}

// int main(int argc, char **argv)
// {
// 	int fd;
// 	if (argc != 2)
// 		fd = 0;
// 	else
// 		fd = open(argv[1], 0);
	
// 	char	*str = get_next_line(fd);
// 	printf("%s", str);

// 	// while (str)
// 	// {
// 	// 	printf("%s", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }

// 	// system("leaks a.out");
// }