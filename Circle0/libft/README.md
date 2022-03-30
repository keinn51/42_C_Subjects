# Welcome to the Libft! ![score](https://img.shields.io/badge/125/100-5cb85c?style=for-the-badge)

> LIBFT는 42에서 필요한 라이브러리를 직접 구현한 프로젝트입니다.

라이브러리가 무엇이고 왜 사용하는지에 대한 이해가 필요하시면 [_라이브러리 만들기_](https://www.joinc.co.kr/w/Site/C/Documents/Make_Library)를 참고해주세요.

Coding convention은 42의 convention을 따라 작성되었습니다.

## Getting started

1. Libft 프로젝트를 클론합니다.

   ```shell
   git clone https://github.com/kohyounghwan/Libft.git
   ```

2. make 명령어를 통해 정적 라이브러리(_libft.a_)를 생성합니다.

   ```shell
   make
   ```

3. 작성하신 코드를 라이브러리와 함께 컴파일 합니다.

   ```shell
   # If code you write is main.c
   gcc libft.a main.c
   ```

## Contents

- [Welcome to the Libft! !score](#welcome-to-the-libft-)
  - [Getting started](#getting-started)
  - [Contents](#contents)
  - [Makefile](#makefile)
  - [Part 1 - Libc functions](#part-1---libc-functions)
    - [ft_memset](#ft_memset)
    - [ft_bzero](#ft_bzero)
    - [ft_memchr](#ft_memchr)
    - [ft_memcpy](#ft_memcpy)
    - [ft_memmove](#ft_memmove)
    - [ft_memcmp](#ft_memcmp)
    - [ft_strlen](#ft_strlen)
    - [ft_strlcpy](#ft_strlcpy)
    - [ft_strlcat](#ft_strlcat)
    - [ft_strchr](#ft_strchr)
    - [ft_strrchr](#ft_strrchr)
    - [ft_strnstr](#ft_strnstr)
    - [ft_strncmp](#ft_strncmp)
    - [ft_atoi](#ft_atoi)
    - [ft_isalpha](#ft_isalpha)
    - [ft_isdigit](#ft_isdigit)
    - [ft_isalnum](#ft_isalnum)
    - [ft_isascii](#ft_isascii)
    - [ft_isprint](#ft_isprint)
    - [ft_toupper](#ft_toupper)
    - [ft_tolower](#ft_tolower)
    - [ft_calloc](#ft_calloc)
    - [ft_strdup](#ft_strdup)
  - [Part 2 - Additional functions](#part-2---additional-functions)
    - [ft_substr](#ft_substr)
    - [ft_strjoin](#ft_strjoin)
    - [ft_strtrim](#ft_strtrim)
    - [ft_split](#ft_split)
    - [ft_itoa](#ft_itoa)
    - [ft_strmapi](#ft_strmapi)
    - [ft_striteri](#ft_striteri)
    - [ft_putchar_fd](#ft_putchar_fd)
    - [ft_putstr_fd](#ft_putstr_fd)
    - [ft_putendl_fd](#ft_putendl_fd)
    - [ft_putnbr_fd](#ft_putnbr_fd)
  - [Bonus](#bonus)
    - [ft_lstnew](#ft_lstnew)
    - [ft_lstlast](#ft_lstlast)
    - [ft_lstsize](#ft_lstsize)
    - [ft_lstadd_front](#ft_lstadd_front)
    - [ft_lstadd_back](#ft_lstadd_back)
    - [ft_lstdelone](#ft_lstdelone)
    - [ft_lstclear](#ft_lstclear)
    - [ft_lstiter](#ft_lstiter)
    - [ft_lstmap](#ft_lstmap)

## Makefile

Makefile은 다음과 같은 rules로 작성되었습니다.

- all  
  Bonus 파트를 제외한 모든 파일을 컴파일하여 라이브러리(_libft.a_)를 만듭니다.

  ```shell
  make
  ```

- bonus  
  Bonus 파트만 컴파일 하여 라이브러리(_libft.a_)를 만듭니다.

  ```shell
  make bonus
  ```

- clean  
  object 파일들을 삭제합니다.

  ```shell
  make clean
  ```

- fclean  
  object 파일들과 라이브러리(_libft.a_)를 삭제합니다.

  ```shell
  make fclean
  ```

- re  
  fclean 후 다시 make 해줍니다.

  ```shell
  make re
  ```

## Part 1 - Libc functions

함수들의 프로토타입은 OS X의 BSD libc를 기준으로 작성되었습니다.

---

### ft_memset

> memory set

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_memset.c)

**Prototype Declaration**

```c
void    *ft_memset(void *b, int c, size_t len);
```

**Description**  
메모리 영역 `b`의 `len` byte까지를 `c`로 초기화합니다.

**Return**  
메모리 영역 `b`의 포인터를 반환

**Ussage**  
메모리 영역을 특정 문자로 초기화할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_bzero

> byte zero

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_bzero.c)

**Prototype Declaration**

```c
void    ft_bzero(void *s, size_t n);
```

**Description**  
메모리 영역 `s`의 `n` bytes까지를 `0`으로 초기화합니다.
초기화 용도로 사용되며, memset과 동일한 역할을 합니다.

**Return**  
없음

**Ussage**  
메모리 영역을 0으로 초기화할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_memchr

> memory character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_memchr.c)

**Prototype Declaration**

```c
void    *ft_memchr(const void *s, int c, size_t n);
```

**Description**  
`n` bytes 까지의 메모리 영역 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다.

**Return**  
처음으로 값 `c`가 나타나는 포인터

**Ussage**  
메모리영역에서 값 `c`의 위치를 찾아낼 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_memcpy

> memory copy

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_memcpy.c)

**Prototype Declaration**

```c
void    *ft_memcpy(void *dst, const void *src, size_t n);
```

**Description**  
메모리 영역 `src`의 `n` bytes만큼을 `dst`로 복사합니다.
절대 src와 dst의 메모리 영역이 겹쳐서는 안됩니다.
메모리 영역이 겹치면, memcpy 대신 memmove를 사용해야합니다.

**Return**  
메모리 영역 `dst`의 포인터를 반환

**Ussage**  
메모리영역을 `n`만큼 복사할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_memmove

> memory move

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_memmove.c)

**Prototype Declaration**

```c
void    *ft_memmove(void *dst, const void *src, size_t len);
```

**Description**  
메모리 영역 `src`의 `len` bytes만큼을 `dst`로 복사합니다.
memcpy와 동일하나, `src`와 `dst`의 메모리 영역이 겹칠 때 사용합니다.

**Return**  
메모리 영역 `dst`

**Ussage**  
메모리 영역을 `len`만큼 복사할 때
`src`와 `dst`의 메모리 영역이 겹칠 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_memcmp

> memory compare

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_memcmp.c)

**Prototype Declaration**

```c
int    ft_memcmp(const void *s1, const void *s2, size_t n);
```

**Description**  
메모리 영역 `s1`과 `s2`를 `n` bytes까지 비교합니다.

**Return**  
`s1`이 크면 양수  
`s2`가 크면 음수  
같으면 0

**Ussage**  
메모리 영역을 비교할 때
정렬에서 비교가 필요할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strlen

> string length

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strlen.c)

**Prototype Declaration**

```c
size_t    ft_strlen(const char *s);
```

**Description**  
문자열 `s`의 길이를 구합니다.

**Return**  
문자열 `s`의 길이

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strlcpy

> string l copy

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strlcpy.c)

**Prototype Declaration**

```c
size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

**Description**  
문자열 `src`에서 `dst`로 `dstsize` bytes 만큼 복사합니다.
문자열 끝에 NUL문자(\0)가 보장된 strcpy 입니다.

**Return**  
`src`의 길이(복사를 시도하려고 하는 길이)

**Ussage**  
문자열을 복사할 때
memcpy 는 메모리 단위로 복사를 하는 함수라고 한다면, 이 함수는 문자열 단위로 복사를 합니다.

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strlcat

> string l cat

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strlcat.c)

**Prototype Declaration**

```c
size_t    ft_strlcat(char *dst, const char *src, size_t dstsize);
```

**Description**  
문자열 `dst` 뒤에 `src`를 이어 붙여주는데, `dstsize` bytes 만큼만 이어붙여줍니다.
문자열 끝에 NUL문자(\0)가 보장된 strcat 입니다. (dstsize의 제일 마지막에 \0을 붙임)

**Return**  
만드려고 시도했던 최종 문자열의 길이

**Ussage**  
NUL이 보장되는 strcat이 필요할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strchr

> string chracter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strchr.c)

**Prototype Declaration**

```c
char    *ft_strchr(const char *s, int c);
```

**Description**  
문자열 `s`에서 문자 `c`가 처음 발견된 곳의 포인터를 반환한다.
`s` 가 정상적인 문자열이 아닐 경우, 문제가 생길 수 있음.

**Return**  
문자 `c`가 처음 발견된 곳의 포인터
문자열 `s`에 문자 `c`가 없으면 NULL 포인터

**Ussage**  
문자열 앞에서부터 특정 문자를 찾을 떄

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strrchr

> string reverse(rear(?)) chracter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strrchr.c)

**Prototype Declaration**

```c
char    *ft_strrchr(const char *s, int c);
```

**Description**  
문자열 `s`의 `뒤에서부터` 문자 `c`가 처음 발견된 곳의 포인터를 반환한다.
`s` 가 정상적인 문자열이 아닐 경우, 문제가 생길 수 있음.

**Return**  
뒤에서부터 문자 `c`가 처음 발견된 곳의 포인터
문자열 `s`에 문자 `c`가 없으면 NULL 포인터

**Ussage**  
문자열 뒤에서부터 특정 문자를 찾을 떄

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strnstr

> string n string

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strnstr.c)

**Prototype Declaration**

```c
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
```

**Description**  
문자열 `haystack`에서 `needle`을 찾아주는데, `len`길이까지만 찾아 줍니다.

**Return**  
`haystack` 에서 찾은 문자열의 포인터

**Ussage**  
문자열에서 특정 문자열이 포함되어 있는지 확인하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strncmp

> string n compare

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strncmp.c)

**Prototype Declaration**

```c
int    ft_strncmp(const char *s1, const char *s2, size_t n);
```

**Description**  
문자열 `s1`과 문자열 `s2`를 `n`만큼 비교해줍니다.

**Return**  
`s1`이 크면 양수  
`s2`가 크면 음수  
같으면 0

**Ussage**  
두 문자열을 비교하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_atoi

> ascii to int

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_atoi.c)

**Prototype Declaration**

```c
int    ft_atoi(const char *str);
```

**Description**  
문자열 `str`을 정수로 바꿔줍니다.

**Return**  
문자열에 `str`에 해당하는 정수

**Ussage**  
문자로된 숫자를 진짜 숫자로 바꿔줄 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_isalpha

> is alphabetic character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_isalpha.c)

**Prototype Declaration**

```c
int    ft_isalpha(int c);
```

**Description**  
`c`가 알파벳 문자인지 아닌지 확인해줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
알파벳이면 1  
알파벳이 아니면 0

**Ussage**  
알파벳 문자인지 아닌지 확인해야할 떄

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_isdigit

> is digit character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_isdigit.c)

**Prototype Declaration**

```c
int    ft_isdigit(int c);
```

**Description**  
`c`가 숫자 문자인지 아닌지 확인해줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
숫자면 1  
숫자가 아니면 0

**Ussage**  
숫자 문자인지 아닌지 확인해야 할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_isalnum

> is alphanumeric character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_isalnum.c)

**Prototype Declaration**

```c
int    ft_isalnum(int c);
```

**Description**  
`c`가 알파벳 또는 숫자 문자인지 아닌지 확인해줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
알파벳이나 숫자면 1
알파벳이나 숫자가 아니면 0

**Ussage**  
알파벳이랑 숫자만 골라내고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_isascii

> is ASCII charecter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_isascii.c)

**Prototype Declaration**

```c
int    ft_isascii(int c);
```

**Description**  
`c`가 ASCII 문자인지 아닌지 확인해줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
ASCII 문자면 1
ASCII 문자가 아니면 0

**Ussage**  
아스키 문자인지 아닌지 확인하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_isprint

> is printable charecter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_isprint.c)

**Prototype Declaration**

```c
int    ft_isprint(int c);
```

**Description**  
`c`가 출력 가능한 문자인지 아닌지 확인해줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
출력 가능한 문자면 1
출력 가능한 문자가 아니면 0

**Ussage**  
출력할 수 있는 문자인지 아닌지 확인하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_toupper

> to upper case charecter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_toupper.c)

**Prototype Declaration**

```c
int    ft_toupper(int c);
```

**Description**  
`c`가 소문자면 대문자로 바꿔줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
대문자로 변환된 문자(int)

**Ussage**  
소문자를 대문자로 바꾸고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_tolower

> to lower case charecter

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_tolower.c)

**Prototype Declaration**

```c
int    ft_tolower(int c);
```

**Description**  
`c`가 대문자면 소문자로 바꿔줍니다.  
EOF(-1)를 처리해주기 위해 int로 받습니다.

**Return**  
소문자로 변환된 문자(int)

**Ussage**  
대문자를 소문자로 바꾸고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_calloc

> contiguous allocation

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_calloc.c)

**Prototype Declaration**

```c
void    *ft_calloc(size_t count, size_t size);
```

**Description**  
0으로 초기화된 연속적인 메모리공간(`count` x `size`)을 할당해줍니다.

**Return**  
할당 성공시 할당된 공간의 포인터  
할당 실패시 NULL 포인터

**Ussage**  
메모리 할당과 동시에 초기화가 필요할 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strdup

> string duplicate

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strdup.c)

**Prototype Declaration**

```c
char    *ft_strdup(const char *s1);
```

**Description**  
문자열 `s1`을 복제해줍니다.

**Return**  
복제한 문자열의 포인터

**Ussage**  
문자열을 복제하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

## Part 2 - Additional functions

libc에는 없지만, 유용한 함수들을 모아둔 파트입니다.

### ft_substr

> subpart of string

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_substr.c)

**Prototype Declaration**

```c
char    *ft_substr(char const *s, unsigned int start, size_t len);
```

**Description**  
문자열 `s`에서 `start` index부터 `len`개 만큼의 부분 문자열을 만들어(복제해) 줍니다.

**Return**  
만들어진(복제된) 부분 문자열의 포인터

**Ussage**  
원래 문자열은 그대로 두고 특정부분만 따서 새로운 문자열을 만들고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strjoin

> string join

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strjoin.c)

**Prototype Declaration**

```c
char    *ft_strjoin(char const *s1, char const *s2);
```

**Description**  
문자열 `s1`에 문자열 `s2`를 이어 붙여서 새로운 문자열로 반환힙니다.

**Return**  
`s1`에 `s2`가 이어 붙여진 문자열

**Ussage**  
원본 문자열을 수정하지 않고, 이어 붙여진 새로운 문자열이 필요할 떄  
ft_strlcat과 유사하지만 새로운 문자열을 만들기 때문에 원본 문자열을 건드리지 않음

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strtrim

> string trim

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strtrim.c)

**Prototype Declaration**

```c
char    *ft_strtrim(char const *s1, char const *set);
```

**Description**  
문자열 `s1`의 앞 뒤로 `set`에 들어 있는 문자들을 제거해주고, 새로운 문자열로 반환해줍니다.

**Return**  
`s1` 앞 뒤로 `set`에 들어 있는 문자들이 제거된 새로운 문자열

**Ussage**  
특정 문자들을 기준으로 앞뒤 내용을 잘라내고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_split

> string split

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_split.c)

**Prototype Declaration**

```c
char    **ft_split(char const *s, char c);
```

**Description**  
문자열 `s1`을 문자 `c`를 기준으로 잘라서, 새로운 문자열배열로 반환해줍니다.

**Return**  
구분자를 기준으로 나뉘어진 문자열 배열

**Ussage**  
특정 구분자를 기준으로 문자열을 쪼개고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_itoa

> integer to ascii character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_itoa.c)

**Prototype Declaration**

```c
char    *ft_itoa(int n);
```

**Description**  
정수 `n`을 **문자열**로 반환해줍니다.

**Return**  
정수 `n`을 문자로 바꾼 문자열

**Ussage**  
정수를 문자열 형태로 변환하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_strmapi

> string mapping iterate

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_strmapi.c)

**Prototype Declaration**

```c
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

**Description**  
문자열 `s`를 순회하면서 각각의 문자에 `f`함수를 적용(mapping) 시켜준 뒤, 새로운 문자열로 반환합니다.(원본 문자열은 건드리지 않는다는 의미)  
`s`는 **문자열**, `f`의 `unsigned int`는 **index**, `char`는 **index에 해당하는 문자**입니다.

**Return**  
`f`함수로 mapping(적용)된 새로운 문자열

**Ussage**  
문자열의 모든 문자열에 동일한 함수를 적용하고 싶을 때  
특정 index에 해당하는 값에만 매핑하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_striteri

> string iterate

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_striteri.c)

**Prototype Declaration**

```c
void    ft_striteri(char *s, void (*f)(unsigned int,
char*));
```

**Description**  
인수로 전달된 문자열의 각 문자에 함수 `f`를 적용하며, `f` 함수의 첫 번째 인수로 문자엻의 인덱스를 전달합니다. 각 문자는 `f` 함수를 향해 주소로 전달되며, 필요하다면 수정됩니다.

**Return**  
없음

**Ussage**  
문자열의 모든 문자열에 동일한 함수를 적용하고 싶을 때
다만 적용만 하고 반환하지는 않고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_putchar_fd

> put character

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_putchar_fd.c)

**Prototype Declaration**

```c
void    ft_putchar_fd(char c, int fd);
```

**Description**  
문자 `c`를 `fd`대로 출력해줍니다.

**Return**  
없음

**Ussage**  
문자를 출력하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_putstr_fd

> put string

**Prototype Declaration**

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_putstr_fd.c)

```c
void    ft_putstr_fd(char *s, int fd);
```

**Description**  
문자열 `s`를 `fd`대로 출력해줍니다.

**Return**  
없음

**Ussage**  
문자열을 출력하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_putendl_fd

> put string end line

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_putendl_fd.c)

**Prototype Declaration**

```c
void    ft_putendl_fd(char *s, int fd);
```

**Description**  
문자열 `s`를 `fd`대로 출력해주고 개행(`\n`)을 붙여줍니다.

**Return**  
없음

**Ussage**  
문자열을 출력하고 개행해주고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_putnbr_fd

> put number

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_putnbr_fd.c)

**Prototype Declaration**

```c
void    ft_putnbr_fd(int n, int fd);
```

**Description**  
숫자 `n`을 `fd`대로 출력해줍니다.

**Return**  
없음

**Ussage**  
숫자를 출력하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

## Bonus

list에 관련된 함수들을 모아둔 파트입니다.

본 파트에서 사용할 list는 다음과 같은 structure를 가지고 있습니다.

```c
typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

---

### ft_lstnew

> list new

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstnew.c)

**Prototype Declaration**

```c
t_list    *ft_lstnew(void *content);
```

**Description**  
`content`의 내용으로 새로운 요소(element)를 만들어 줍니다.  
`content`가 NULL일 때도 `content`가 NULL인 요소를 만들어 줍니다.

**Return**  
새로 만들어진 요소의 포인터를 반환합니다.

**Ussage**  
새로운 요소(element)를 만들고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstlast

> list last

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstlast.c)

**Prototype Declaration**

```c
t_list    *ft_lstlast(t_list *lst);
```

**Description**  
`lst`의 마지막 요소를 찾아줍니다.

**Return**  
`Lst` 마지막 요소의 포인터

**Ussage**  
리스트의 마지막 요소에 접근하고 싶을 때  
마지막 요소에 접근해서 무언가 하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstsize

> list size

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstsize.c)

**Prototype Declaration**

```c
int    ft_lstsize(t_list *lst);
```

**Description**  
`lst`의 길이를 구해서 반환해줍니다.

**Return**  
`lst`의 길이

**Ussage**  
리스트의 길이를 구하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstadd_front

> list add front

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstadd_front.c)

**Prototype Declaration**

```c
void    ft_lstadd_front(t_list **lst, t_list *new);
```

**Description**  
`lst` 리스트 앞에 `new` 요소를 붙여 줍니다.

**Return**  
없음

**Ussage**  
리스트 `앞에` 새로운 요소를 이어 붙이고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstadd_back

> list add back

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstadd_back.c)

**Prototype Declaration**

```c
void    ft_lstadd_back(t_list **lst, t_list *new);
```

**Description**  
`lst` 리스트 뒤에 `new` 요소를 붙여 줍니다.

**Return**  
없음

**Ussage**  
리스트 `뒤에` 새로운 요소를 이어 붙이고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstdelone

> list delete one

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstdelone.c)

**Prototype Declaration**

```c
void    ft_lstdelone(t_list *lst, void (*del)(void*));
```

**Description**  
`lst` 요소를 삭제합니다.  
`lst->content`에 `del`을 적용해주고 `lst`를 free합니다.  
`lst->next`는 free하지 않습니다.

**Return**  
없음

**Ussage**  
요소의 content을 지우고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstclear

> lst clear

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstclear.c)

**Prototype Declaration**

```c
void    ft_lstclear(t_list **lst, void (*del)(void*));
```

**Description**  
`lst` 의 content를 지워줍니다.(리스트를 초기화 해줍니다.)  
`lst->next`는 free하지 않습니다.

**Return**  
없음

**Ussage**  
리스트 전체를 지우고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstiter

> list iteration

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstiter.c)

**Prototype Declaration**

```c
void    ft_lstiter(t_list *lst, void (*f)(void *));
```

**Description**  
리스트를 순회하면서 `lst`에 `f`를 적용해줍니다.

**Return**  
없음

**Ussage**  
리스트 전체에 함수를 적용하고 싶을 때

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>

---

### ft_lstmap

> list mapping

**code**

[Here](https://github.com/keinn51/C_Language_Subjects/blob/master/done_sub/libft/libft_END/ft_lstmap.c)

**Prototype Declaration**

```c
t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

**Description**  
리스트를 순회하면서 `lst`에 `f`를 적용하고, 적용에 성공한 함수들의 리스트를 반환합니다. `del` 함수는 요소를 지우고 싶을 때 사용합니다. 이는 필요할 때에만 쓰입니다.

**Return**  
`f`가 적용된 리스트의 포인터

**Ussage**  
리스트에서 `f`가 적용된 리스트들만 추리고 싶을 때

lstiter는 반환형이 없는 `f`를 사용하였고, lstmap은 반환형이 있는 `f`입니다.

<div align = "right">
    <b><a href = "#Contents">↥ back to top</a></b>
</div>
