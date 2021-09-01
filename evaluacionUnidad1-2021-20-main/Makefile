CC = gcc
CFLGAS = -Wall
DEPS = student.h

%.o: %.c $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@

main: main.o student.o
	$(CC) $(CFLGAS) -o main main.o student.o

clean:
	rm main main.o student.o