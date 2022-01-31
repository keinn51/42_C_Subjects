#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct s_list
{
	int			lst_fd;
	char		*content;
	struct s_list	*next;
}	t_list;

void ftft(void *str)
{
	printf("%c", *(char *)str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
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
		return (NULL);
	}
	result->lst_fd = fd;
	result->content = content;
	result->next = NULL;
	return (result);
}

int main()
{
	char	*str = malloc(5);

	str[0] = 'a';
		str[1] = 'a';
			str[2] = 'a';

	printf("%s", str);
	free(str);
	str[0] = 'c';
	// printf("%s", str);
}
