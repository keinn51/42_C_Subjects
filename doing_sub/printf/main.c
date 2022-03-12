#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end가 정의된 헤더 파일
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *types, ...)
{
  va_list ap;
  int i = 0;
  char str[1024];

  va_start(ap, types);
  while (types[i] != '\0')
  {
    if (types[i] == 'i')
    {
      write(1, ft_itoa(va_arg(ap, int), str, 10), ft_strlen(str));
    }
    else if(types[i] == 'c')
    {
      write(1, va_arg(ap, char), 1);
    }
    else if(types[i] == 's')
    {
      write(1, va_arg(ap, char *), ft_strlen())
    }
  }
  
}

void printValues(char *types, ...)    // 가변 인자의 자료형을 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록
    int i = 0;
    char temp[3];

    va_start(ap, types);        // types 문자열에서 문자 개수를 구해서 가변 인자 포인터 설정
    while (types[i] != '\0')    // 가변 인자 자료형이 없을 때까지 반복
    {
        switch (types[i])       // 가변 인자 자료형으로 분기
        {
        case 'i':                                // int형일 때
          itoa(va_arg(ap, int), temp, 10);
          write(1, temp, 3); // int 크기만큼 값을 가져옴
                                   // ap를 int 크기만큼 순방향으로 이동
          break;
        case 'd':                                // double형일 때
            printf("%f ", va_arg(ap, double));   // double 크기만큼 값을 가져옴
                                                 // ap를 double 크기만큼 순방향으로 이동
            break;
        case 'c':                                // char형 문자일 때
            printf("%c ", va_arg(ap, char));     // char 크기만큼 값을 가져옴
                                                 // ap를 char 크기만큼 순방향으로 이동
            break;
        case 's':                                // char *형 문자열일 때
            printf("%s ", va_arg(ap, char *));   // char * 크기만큼 값을 가져옴
                                                 // ap를 char * 크기만큼 순방향으로 이동
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);    // 가변 인자 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}

int main()
{
    printValues("i", 10);                                       // 정수
    printValues("ci", 'a', 10);                                 // 문자, 정수
    printValues("dci", 1.234567, 'a', 10);                      // 실수, 문자, 정수
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // 문자열, 정수, 문자, 실수

    return 0;
}