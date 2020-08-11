# 通配符 %.cpp/%.o任意的.cpp/.o

TAR=main
OBJ=main.o hello1.o hello2.o
CC:=g++
RM:=rm

$(TAR):$(OBJ)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:clean
clean:
	$(RM) *.o main