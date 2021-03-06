#include <stdio.h>
#include <setjmp.h>

jmp_buf g_save;

void D()
{
    printf("%s():Begin\n", __FUNCTION__);

    printf("%s():Jump Now\n", __FUNCTION__);
    longjmp(g_save, 666);    //跳转

    printf("%s():End\n", __FUNCTION__);
}

void C()
{
    printf("%s():Begin\n", __FUNCTION__);
    printf("%s():Call D\n", __FUNCTION__);
    D();
    printf("%s():D Retuned\n", __FUNCTION__);
    printf("%s():End\n", __FUNCTION__);
}

void B()
{
    printf("%s():Begin\n", __FUNCTION__);
    printf("%s():Call C\n", __FUNCTION__);
    C();
    printf("%s():C Retuned\n", __FUNCTION__);
    printf("%s():End\n", __FUNCTION__);
}

void A()
{
    printf("%s():Begin\n", __FUNCTION__);

    int ret;
    ret = setjmp(g_save);
    if(ret == 0)    //从此处跳转 设置跳转点
    {
        printf("%s():Call B\n", __FUNCTION__);
        B();
        printf("%s():B Retuned\n", __FUNCTION__);
    }
    else    //从外部跳回 返回跳转点
    {
        printf("%s():Jumped Back Here With Code %d\n", __FUNCTION__, ret);
    }

    printf("%s():End\n", __FUNCTION__);
}

int main()
{
    printf("%s():Begin\n", __FUNCTION__);
    printf("%s():Call A\n", __FUNCTION__);
    A();
    printf("%s():A Retuned\n", __FUNCTION__);
    printf("%s():End\n", __FUNCTION__);

    return 0;
}
