#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t t;
    time(&t);   //获取时间戳
    printf("%ld\n", t);

    struct tm* gm;
    gm = gmtime(&t);    //时间戳->结构体
    printf("%d-%d-%d\t%d:%d:%d\n", gm->tm_year + 1900, gm->tm_mon + 1, gm->tm_mday,
           gm->tm_hour, gm->tm_min, gm->tm_sec);

    struct tm* local;
    local = localtime(&t);  //时间戳->结构体
    printf("%d-%d-%d\t%d:%d:%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
           local->tm_hour, local->tm_min, local->tm_sec);

    char buf[BUFSIZ];
    strftime(buf, BUFSIZ, "%Y-%m-%d\t%H:%M:%S", local);  //格式化结构体
    puts(buf);

    local->tm_mday += 100;
    t = mktime(local);  //更改时间 返回时间戳
    printf("%ld\n", t);
    strftime(buf, BUFSIZ, "%Y-%m-%d\t%H:%M:%S", local);
    puts(buf);

    return 0;
}