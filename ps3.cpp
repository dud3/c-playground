#include <stdio.h>
#include <string>

using namespace std;

int main(void)
{
    string s = "Hello, wordl";
    string* p = &s; // Here you get an address of s

    printf("%p\n", p);
}