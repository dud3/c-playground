#include <stdio.h>
#include <stdlib.h>
// #include <curses.h>

#include "SDL.h"

int main() 
{
	Uint8 *u8;

	char a;
	a = 'a';

	printf("%s\n", &a);
	
	int c;

	while (1) {  
        	c = getchar(); 

        	/* If a key has been pressed */
        	if (c != '\0') {
		
           	 	/* Do something */
            		// c = '\0'; // and put it back to \0
        	}

		printf("char: %c\n", c);

        	/* Do something else */
    	}


	return 0;
}
