#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

//终端运行 传入文件名
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        perror("argc error");
        exit(-1);
    }

    struct stat st;     //文件属性结构体
    if(stat(argv[1], &st) < 0)
    {
        perror("stat error");
        exit(-1);
    }

    printf("设备号：%d\n", st.st_dev);
    printf("模式：%hu\n", st.st_mode);
    printf("链接数：%hu\n", st.st_nlink);
    printf("inode节点：%lld\n", st.st_ino);
    printf("所有者：%u\n", st.st_uid);
    printf("所属组：%u\n", st.st_gid);
    printf("特殊设备号：%d\n", st.st_rdev);
    printf("大小：%lld\n", st.st_size);
    printf("块数量：%lld\n", st.st_blocks);
    printf("块大小：%d\n", st.st_blksize);
    printf("最后访问时间：%ld\n", st.st_atimespec.tv_sec);
    printf("最后修改时间：%ld\n", st.st_mtimespec.tv_sec);
    printf("状态最后修改时间：%ld\n", st.st_ctimespec.tv_sec);
}