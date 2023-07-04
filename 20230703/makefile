TARGET : stuff
OBJS : stuff.o square.o factorial.o
CC : gcc

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) -c $<

%.o : %.c
	$(CC) -c -o $@ $<