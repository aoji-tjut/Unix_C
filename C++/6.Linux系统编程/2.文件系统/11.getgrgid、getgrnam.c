#include <stdio.h>
#include <stdlib.h>
#include <grp.h>

//终端运行 传入gid、用户组
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        perror("argc error");
        exit(-1);
    }

    struct group* grp;

    grp = getgrgid(atoi(argv[1]));
    puts(grp->gr_name);

    grp = getgrnam(argv[2]);
    printf("%d\n", grp->gr_gid);

    return 0;
}