#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "hello world";
    printf("%p\n", str1);
    printf("size=%lu, len=%lu, %s\n", sizeof(str1), strlen(str1), str1);
    str1[5] = '!';
    printf("size=%lu, len=%lu, %s\n", sizeof(str1), strlen(str1), str1);
    printf("\n");

    char* str2 = "hello world";
    printf("%p\n", str2);
    printf("size=%lu, len=%lu, %s\n", sizeof(str2), strlen(str2), str2);
    str2 = "hello!world";
    printf("size=%lu, len=%lu, %s\n", sizeof(str2), strlen(str2), str2);

    return 0;
}