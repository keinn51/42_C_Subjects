#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void ftft(void *str)
{
	printf("%c", *(char *)str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main()
{
	char	*str;
	char	*str1 = "";
	free(str1);
	printf("%lu", sizeof(str));
}
