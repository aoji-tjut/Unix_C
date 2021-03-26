# src = $(wildcard *.c) 匹配当前目录下所有.c文件 赋值给src
# obj = $(patsubst %.c, %.o, $(src)) 把src中.c文件替换为.o 赋值给obj

SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
TAR=main
CC:=g++
RM:=rm

$(TAR):$(OBJ)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:clean
clean:
	$(RM) *.o main
