TARGET = labI1
SRCS = main.c\
       mkarr.c\
       getmid.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)
		     
.c.o:
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)
