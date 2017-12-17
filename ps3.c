#include <stdio.h>

int main(void)
{
    char s[] = "Hello, wordl";
    char* p = &s; // Here you get an address of s

    printf("%p\n", p);
    printf("%c\n", *p);
}