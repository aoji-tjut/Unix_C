#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//若要跳出信号处理函数 应使用sigsetjmp和siglongjmp 可以保留mask信号掩码信息

void DealSignal()
{
	printf("|");
}

//终端运行 实现功能：信号在每行打印过程中不响应 在下一段行首响应
int main()
{
	signal(SIGINT, DealSignal);

	sigset_t set, old_set;//信号集
	sigemptyset(&set);//置空信号集
	sigaddset(&set, SIGINT);//将SIGINT信号添加至信号集
	sigprocmask(SIG_UNBLOCK, &set, &old_set);//将set信号集解除阻塞 保留之前状态至old_set
	
	while(1)
	{
		sigprocmask(SIG_BLOCK, &set, NULL);//阻塞信号集 阻塞过程中只接收信号但不响应

		for(int i = 0; i < 5; i++)
		{
			printf("-");
			fflush(stdout);
			sleep(1);
		}

		printf("\n");
		
		sigprocmask(SIG_UNBLOCK, &set, NULL);//解除阻塞信号集
	}
	
	sigprocmask(SIG_SETMASK, &old_set, NULL);//恢复旧信号集 保证其它模块不受影响

	return 0;
}
