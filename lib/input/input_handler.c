/**
 * Linux only
 */
#include <stdio.h>
#include <termios.h> // TCSANOW, ECHO, ICANON
#include <unistd.h>

#include "input_handler.h"

void ih_key_down(void (*fn)(void* data))
{
	static struct termios oldt, newt;

        /**
         * tcgetattr gets the parameters of the current terminal
         * STDIN_FILENO will tell tcgetattr that it should write the settings
         * of stdin to oldt
         */
        tcgetattr(STDIN_FILENO, &oldt);

        /* now the settings will be copied */
        newt = oldt;

        /**
         * ICANON normally takes care that one line at a time will be processed
         * that means it will return if it sees a "\n" or an EOF or an EOL
         */
        newt.c_lflag &= ~(ICANON | ECHO);

        /**
         * Those new settings will be set to STDIN
         * TCSANOW tells tcsetattr to change attributes immediately.
         */
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        int ch;
        while (1) {
                ch = getchar();
                (*fn)(&ch);
        }

        /* restore the old settings */
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

