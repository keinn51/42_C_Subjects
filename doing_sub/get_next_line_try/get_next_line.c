/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:10:27 by kyungsle          #+#    #+#             */
/*   Updated: 2022/01/31 14:03:17 by kyungsle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> //have to remove!!
# define BUFFER_SIZE 4	//have to remove!!

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
		return (0);
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
		return (NULL);
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
 
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	temp = *lst;
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*temp;
	char	*s1_free;

	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	s1_free = (char *)s1;
	if (!temp)
		return (0);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	free((void *)s1_free);
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

	i++;

	while (temp_buff[i])
		rtn[j++] = temp_buff[i++];

	rtn[j] = '\0';

	free(temp_buff);

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
	// int		i = 0;
	ssize_t	len;

	rtn = NULL;

	if (!ft_lstfind(fd, buff_lst))
		ft_lstadd_back(&buff_lst, ft_lstnew(ft_strdup(""), fd));

	curr_lst = ft_lstfind(fd, buff_lst);
	if (!curr_lst || !curr_lst->content)
		return (NULL);

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);

	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buff[len] = '\0';

		// printf("<1>inside read buff: %s\n", buff);

		curr_lst->content = ft_strjoin(curr_lst->content, buff);
		
		if (is_endline(buff, BUFFER_SIZE) || len <= 0)
		{
			// printf("is_endline buff %s\n", buff);
			// printf("is_endline curr_lst %s\n", curr_lst->content);
			rtn = set_result(curr_lst->content);
			curr_lst->content = save_result(curr_lst->content);
			// printf("is_endline lower buff %s", buff);
		}
		

		if (rtn != NULL)
		{
			// printf("Inner return!\n");
			free(buff);
			return (rtn);
		}
	}

	//	printf("last curr %s$\n", curr_lst->content);


	if (*(curr_lst->content))
	{
		// printf("inside lower lstfind %s\n",curr_lst->content);
		rtn = set_result(curr_lst->content);
		curr_lst->content = save_result(curr_lst->content);
		free(buff);
	}


	return (rtn);
}


#include <stdio.h>

int main()
{
	
   char   buff[BUFFER_SIZE];
   int    fd;
   int     i = 0;
   char *res;

   if ( 0 < ( fd = open( "./test.txt", O_RDONLY)))
   {
	while ((res = get_next_line(fd)))
	{
		printf ("★★★(%d) result: %s$\n", i++, res );
		free(res);
	}
      close(fd);
   }
   else {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}