#include <stdio.h>
#include <unistd.h>

//终端运行
int main()
{
    char* str = getpass("Enter string:");
    char* password = crypt(str, "hello world!");
    puts(password);

    return 0;
}