# 内置变量
# $@所有目标文件
# $^所有依赖文件
# $<所有依赖文件的第一个文件 在模式规则中可将依赖文件依次取出套用模式规则

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