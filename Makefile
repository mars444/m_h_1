TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c \
       project/src/write_client_to_file.c \
	   project/src/write_to_file_test.c \
	   project/src/write_transaction.c \
	   project/src/black_record.c \
	   project/src/read_from_file_test.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./linters/run.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat
