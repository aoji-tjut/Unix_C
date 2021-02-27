#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

//终端运行 -Y(2/4)=year -M=mouth -D=day -h(12/24)=hour -m=minute -s=second
int main(int argc, char* argv[])
{
    time_t t;
    time(&t);

    struct tm* local;
    local = localtime(&t);

    int opt;
    char fmt_buf[BUFSIZ];
    fmt_buf[0] = '\0';
    FILE* f = stdout;
    while(1)
    {
        //带参数的选项后加冒号 使用optarg处理
        //第一个参数为-时 遇到非选项参数返回1 使用optind处理
        opt = getopt(argc, argv, "-Y:MDh:ms");
        if(opt < 0)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                puts("qwe");
                f = fopen(argv[optind - 1], "w");
                if(f == NULL)
                {
                    perror("fopen()");
                    f = stdout;
                }
                break;
            case 'Y':
                if(strcmp(optarg, "2") == 0)
                {
                    strcat(fmt_buf, "%y ");
                }
                else if(strcmp(optarg, "4") == 0)
                {
                    strcat(fmt_buf, "%Y ");
                }
                else
                {
                    puts("Invaild Arg");
                }
                break;
            case 'M':
                strcat(fmt_buf, "%m ");
                break;
            case 'D':
                strcat(fmt_buf, "%d ");
                break;
            case 'h':
                if(strcmp(optarg, "12") == 0)
                {
                    strcat(fmt_buf, "%I(%P) ");
                }
                else if(strcmp(optarg, "24") == 0)
                {
                    strcat(fmt_buf, "%H ");
                }
                else
                {
                    puts("Invaild Arg");
                }
                break;
            case 'm':
                strcat(fmt_buf, "%M ");
                break;
            case 's':
                strcat(fmt_buf, "%S ");
                break;
            default:
                break;
        }
    }

    char time_buf[BUFSIZ];
    strftime(time_buf, BUFSIZ, fmt_buf, local);
    strcat(time_buf, "\n");
    fputs(time_buf, f);

    if(f != stdout)
    {
        fclose(f);
    }

    return 0;
}
