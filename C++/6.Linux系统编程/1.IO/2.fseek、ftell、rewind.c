#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("./file.txt", "w+");   //读写形式打开文件 有则清空 无则创建
    if(!fp)
    {
        perror("open file error");
        exit(-1);
    }

    char c = 'A';
    for(int i = 1; i <= 3; i++)     //写入A、B、C
    {
        fputc(c++, fp);
    }   //写入完成后 文件指针指向最后字节的下一位置

    fseek(fp, -2, SEEK_CUR);    //将文件指针从当前位置向前偏移两个字节
    while(!feof(fp))
    {
        printf("%c", fgetc(fp));
    }   //读取完成后 文件指针指向最后字节的下一位置
    printf("\n");

    printf("%ld\n", ftell(fp));     //返回文件指针相对于文件首的偏移量

    rewind(fp);     //将文件指针移至文件首
    printf("%ld\n", ftell(fp));

    fclose(fp);

    return 0;
}