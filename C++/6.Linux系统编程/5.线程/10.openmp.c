#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//编译连接使用-fopenmp
//线程个数等于处理器核心数

int main()
{
    puts("Begin");

#pragma omp parallel
    {
        printf("Thread %d\n", omp_get_thread_num());
        printf("Thread %d\n", omp_get_thread_num());
        printf("Thread %d\n", omp_get_thread_num());
    }

    puts("End");

    return 0;
}
