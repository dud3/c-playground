#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        var str = 'CABAAXBYAB';
        var start_str = 'A';
        var end_str = 'B';
        var counter = 0;
    */
    char str[] = "CABAAXBYAB";
    char str_start = 'A';
    char str_end = 'B';
    
    int i;
    int j;
    int counter = 0;
    for(i = 0; i < strlen(str); i++) {
        if((str[i] == str_start) == 1) {
            for(j = i; j < strlen(str); j++) {
                if((str[j] == str_end) == 1) {
                    counter++;
                }
            }
        }
    }
    
    printf("%d\n", counter);
    
    return 0;
}