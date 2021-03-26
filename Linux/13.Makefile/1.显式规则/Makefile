# 文件名必须为Makefile 没有后缀
# 1.预编译 -E	展开头文件宏替换 去掉注释
# 2.编译 -S	编译为汇编文件
# 3.汇编 -c	编译为二进制文件
# 4.链接		编译为可执行文件
# *.cpp -> *.i -> *.S -> *.o -> 可执行文件

# 目标文件:依赖文件
# [TAB]命令
# 默认第一个文件是最终目标 从下向上
# ALL:可以指定最终目标
# 伪目标 .PHONY:命令

hello:hello.o
	g++ hello.o -o hello

hello.o:hello.S
	g++ -c hello.S -o hello.o

hello.S:hello.i
	g++ -S hello.i -o hello.S

hello.i:hello.cpp
	g++ -E hello.cpp -o hello.i

.PHONY:cleantemp cleanall
cleantemp:
	rm hello.o hello.s hello.i
cleanall:
	rm hello.o hello.s hello.i hello