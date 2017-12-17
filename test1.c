#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "a";
    char a1[] = "a";
    char b[] = "b";
    
    int cmp = 0;
    
    cmp = strcmp(a, b);
    printf("%d\n", cmp);
    
    int cmp1 = 0;
    cmp1 = strcmp(a, a1);
    printf("%d\n", cmp1);
    
    char a2 = 'a';
    char b2 = 'a';
    char c2 = 'b';

    printf("%d\n", a2 == b2);
    printf("%d\n", a2 == c2);
    
    
    return 0;
}