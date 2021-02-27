#include <stdio.h>

//缓冲区：合并系统调用
//全缓冲(默认)：缓冲区满则刷新、fflush()强制刷新
//行缓冲(终端)：换行则刷新、缓冲区满则刷新、fflush()强制刷新
//无缓冲(stderr)：直接刷新

//debug运行
int main()
{
    char buf[6];
    for(int i = 0; i < 5; i++)
    {
        static char c = 'A';
        buf[i] = c++;
    }
    puts(buf);

    for(int i = 0; i < 5; i++)
    {
        printf("%c", buf[i]);
    }
    printf("\n");   //换行刷新

    for(int i = 0; i < 5; i++)
    {
        printf("%c", buf[i]);
        fflush(stdout);     //强制刷新
    }
    printf("\n");

    setvbuf(stdout, buf, _IONBF, sizeof(buf));  //设置无缓冲格式

    for(int i = 0; i < 5; i++)
    {
        printf("%c", buf[i]);
    }

    return 0;
}