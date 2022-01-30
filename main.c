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
	ft_putchar_fd(66, 1);
}