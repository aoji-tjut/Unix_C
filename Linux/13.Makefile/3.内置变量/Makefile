# 内置变量 $@所有目标文件 $^所有依赖文件 $<所有依赖文件的第一个文件

TAR=hello
OBJ=hello.o
SRC=hello.cpp
CC:=g++
RM:=rm

$(TAR):$(OBJ)
	$(CC) $^ -o $@

$(OBJ):$(SRC)
	$(CC) -c $^ -o $@

.PHONY:clean
clean:
	$(RM) hello.o hello