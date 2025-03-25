# Makefile
CC = gcc
CFLAGS =
OBJS = ch1_3_main.o ch1_3_addnum.o
LIBS =

# 기본 타겟
all: add.out

# add.out 타겟을 만들기 위한 규칙
add.out: $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

# ch1_3_main.o 타겟을 만들기 위한 규칙
ch1_3_main.o: ch1_3_main.c
	$(CC) $(CFLAGS) -c ch1_3_main.c

# ch1_3_addnum.o 타겟을 만들기 위한 규칙
ch1_3_addnum.o: ch1_3_addnum.c
	$(CC) $(CFLAGS) -c ch1_3_addnum.c

# clean 타겟 (빌드된 파일을 삭제)
clean:
	rm -f $(OBJS) add.out *.o core

