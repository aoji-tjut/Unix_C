# 变量 =(替换) +=(追加) :=(恒等于 类似常量)
# 使用变量$()
# 类似宏替换

TAR=hello
OBJ=hello.o
SRC=hello.cpp
CC:=g++
RM:=rm

$(TAR):$(OBJ)
	$(CC) $(OBJ) -o $(DST)

$(OBJ):$(SRC)
	$(CC) -c $(SRC) -o $(OBJ)

.PHONY:clean
clean:
	$(RM) hello.o hello