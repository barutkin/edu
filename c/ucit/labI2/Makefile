TARGET = labI2
SRCS = main.c\
       mycos.c\
       mycosVScos.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -lm

.PHONY: all clean

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)
		     
.c.o:
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)
