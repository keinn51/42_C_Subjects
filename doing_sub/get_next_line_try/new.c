#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> //have to remove!!
# define BUFFER_SIZE 4	//have to remove!!

#include <fcntl.h> //have to remove!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	if (argc != 2)
		fd = 0;
	else
		fd = open(argv[1], 0);
	
	char	*str = get_next_line(fd);
	printf("%s", str);

	// while (str)
	// {
	// 	printf("%s", str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// }

	// system("leaks a.out");
}