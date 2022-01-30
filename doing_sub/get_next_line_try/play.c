#include <stdio.h>         // printf()
#include <string.h>        // strlen()
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

int main()
{
   char  temp[100];
   int    fd;

   if ( 0 < ( fd = open( "./test.txt", O_RDONLY))) {
      printf("%zd", read( fd, temp, 100));
      // printf("%d",fd);  //3
      close(fd);
   } else {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}