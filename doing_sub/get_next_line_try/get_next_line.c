/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:10:27 by kyungsle          #+#    #+#             */
/*   Updated: 2022/01/31 21:24:48 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> //have to remove!!
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1	//have to remove!!
# endif

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_list	*ft_lstnew(char *content, int	fd)
{
	t_list	*result;

	if (!content)
		return (NULL);
	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
	{
		free(content);
		content = NULL;
		return (NULL);
	}
	result->lst_fd = fd;
	result->content = content;
	result->next = NULL;
	return (result);
}

t_list	*ft_lstfind(int	fd, t_list *lst)
{
	while (lst && lst->lst_fd != fd)
		lst = lst->next;
	if (!lst)
		return (NULL);
	return (lst);
}

void	ft_lstdel(t_list **head_lst, t_list **curr_lst)
{
	t_list *temp;

	temp = *head_lst;
	if (temp->lst_fd == (*curr_lst)->lst_fd)
	{
		// printf("%d\n", curr_lst);
		free((*curr_lst)->content);
		free(*curr_lst);
		if (!temp->next)
			*head_lst = NULL;
		return ;
	}
	while (temp && temp->next)
	{
		if (temp->next->lst_fd == (*curr_lst)->lst_fd)
		{
			// printf("hello2");
			temp->next = (*curr_lst)->next;
			free((*curr_lst)->content);
			free(*curr_lst);
			return ;
		}
		temp = temp->next;
	}
}
 
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list *temp;

// 	temp = *lst;
// 	if (!lst)
// 		return ;
// 	if (!(*lst))
// 		*lst = new;
// 	else
// 	{
// 		while (temp->next)
// 			temp = temp->next;
// 		temp->next = new;
// 	}
// }

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return (0);
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*temp;
	char	*s1_free;

	s1_free = s1;
	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (0);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	free(s1_free);
	s1_free = NULL;
	return (result);
}

char	*save_result(char *temp_buff)
{
	size_t	res_size;
	size_t	i;
	size_t	j;
	char	*rtn;

	i = 0;
	j = 0;

	res_size = ft_strlen(temp_buff);

	while (temp_buff[i] != '\n')
	{
		if (!temp_buff[i])
			return (ft_strdup(""));
		i++;
	}

	rtn = (char *)malloc(sizeof(char) * (res_size - i));
	if (!rtn)
		return (NULL);

	i++;

	while (temp_buff[i])
		rtn[j++] = temp_buff[i++];

	rtn[j] = '\0';

	free(temp_buff);
	temp_buff = NULL;
	return (rtn);
}

char	*set_result(char *temp_buff)
{
	size_t	i;
	char	*rtn;

	i = 0;
	
	while (temp_buff[i] && temp_buff[i] != '\n')
		i++;

	if (temp_buff[i] == '\n')
		i++;

	rtn = (char *)malloc(sizeof(char) * (i + 1));

	if (!rtn)
		return (NULL);

	i = 0;

	while (temp_buff[i] && temp_buff[i] != '\n')
	{
		rtn[i] = temp_buff[i];
		i++;
	}

	if (temp_buff[i] == '\n')
	{
		rtn[i] = temp_buff[i];
		i++;
	}

	rtn[i] = '\0';

	return (rtn);

}

int	is_endline(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && i < size - 1)
	{
		i++;
	}
	
	if (str[i] == '\n' || !str[i])
		return (1);
	
	return (0);
}




char	*get_next_line(int fd)
{
	static t_list	*buff_lst;
	t_list	*curr_lst;
	char	*buff;
	char	*rtn;
	ssize_t	len;

	rtn = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	

	if (!ft_lstfind(fd, buff_lst))
		if (!ft_lstadd_front(&buff_lst, ft_lstnew(ft_strdup(""), fd)))
			return (NULL);

	curr_lst = ft_lstfind(fd, buff_lst);
	// curr_lst 와 buff_lst 의 주소값이 동일한 것 확인
	// free(curr_lst) 오류 없음 확인


	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		ft_lstdel(&buff_lst, &curr_lst);
		return (NULL);
	}

	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			ft_lstdel(&buff_lst, &curr_lst);
			curr_lst = NULL;
			free(buff);
			buff = NULL;
			return (NULL);
		}
		if (len == 0)
			break ;
		buff[len] = '\0';

		// printf("<1>inside read buff: %s\n", buff);

		curr_lst->content = ft_strjoin(curr_lst->content, buff);

		if (!curr_lst->content)
		{
			ft_lstdel(&buff_lst, &curr_lst);
			curr_lst = NULL;
			free(buff);
			buff = NULL;
			return (NULL);
		}
		
		if (is_endline(buff, BUFFER_SIZE))
		{
			// printf("is_endline buff %s\n", buff);
			// printf("is_endline curr_lst %s\n", curr_lst->content);
			rtn = set_result(curr_lst->content);
			if (!rtn)
			{
				ft_lstdel(&buff_lst, &curr_lst);
				curr_lst = NULL;
				free(buff);
				buff = NULL;
				return (NULL);
			}

			curr_lst->content = save_result(curr_lst->content);
			if (!curr_lst->content)
			{
				ft_lstdel(&buff_lst, &curr_lst);
				curr_lst = NULL;
				free(buff);
				buff = NULL;
				return (NULL);
			}
			// printf("curr_lst->content %d\n", !curr_lst->content);

		}

		if (rtn != NULL)
		{
			// printf("Inner return!\n");
			free(buff);
			buff = NULL;
			return (rtn);
		}
	}

		// printf("last curr %s$\n", buff_lst->content);


	if (curr_lst && curr_lst->content)
	{
		if (*(curr_lst->content))
		{
			// printf("inside lower lstfind %s\n",buff_lst->content);
			rtn = set_result(curr_lst->content);
			if (!rtn)
			{
				ft_lstdel(&buff_lst, curr_lst);
				curr_lst = NULL;
				free(buff);
				buff = NULL;
				return (NULL);
			}
			curr_lst->content = save_result(curr_lst->content);
			if (!curr_lst->content)
			{
				ft_lstdel(&buff_lst, &curr_lst);
				free(buff);
				buff = NULL;
				return (NULL);
			}
		}
		else
		{
			// printf("lst del");
			ft_lstdel(&buff_lst, &curr_lst);
			curr_lst = NULL;
			// buff_lst = NULL;
			// printf("%d", curr_lst->lst_fd);
		}
	}
	
	free(buff);
	buff = NULL;
	return (rtn);
}


#include <stdio.h>

int main()
{
	int fd = open("42_no_nl", O_RDONLY);
	char *str = get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

	// close(fd);
	// get_next_line(fd);
	system("leaks a.out");
	printf("%s\n", str);
//    char   buff[BUFFER_SIZE];
//    int    fd;
//    int     i = 0;
//    char *res;

//    if ( 0 < ( fd = open( "./42_no_nl", O_RDONLY)))
//    {
// 	while ((res = get_next_line(fd)))
// 	{
// 		printf ("★★★(%d) result: %s$\n", i++, res );
// 		free(res);
// 	}
//       close(fd);
//    }
//    else {
//       printf( "파일 열기에 실패했습니다.\n");
//    }
//    return 0;
}