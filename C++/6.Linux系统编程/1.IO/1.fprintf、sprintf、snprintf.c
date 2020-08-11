#include <stdio.h>
#include <string.h>

int main()
{
    int i = 666;
    char str[16];
    memset(str, 0, sizeof(str));

    fprintf(stdout, "fprintf\n");   //指定输出流

    sprintf(str, "sprintf:%d\n", i);    //字符串格式化
    fputs(str, stdout);
    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "snprintf:%d\n", i);     //指定长度字符串格式化
    fputs(str, stdout);

    return 0;
}