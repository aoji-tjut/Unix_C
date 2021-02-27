#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

//终端运行 传入uid、用户名
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        perror("argc error");
        exit(-1);
    }

    struct passwd* pwd;

    pwd = getpwuid(atoi(argv[1]));
    puts(pwd->pw_name);

    pwd = getpwnam(argv[2]);
    printf("%d\n", pwd->pw_uid);

    return 0;
}