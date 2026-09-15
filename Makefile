CC = mpicc
CFLAGS = -Wall -Wextra -g

PROGRAMS = first_file second_file third_file fourth_file fifth_file

all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PROGRAMS)
