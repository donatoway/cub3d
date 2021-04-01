SRCS = get_next_line.c get_next_line_utils.c

FLAGS = -Wall -Wextra -Werror 

CC = gcc

all: 
	$(CC) -c $(FLAGS) $(SRCS)
	ar -r get_next_line.a get_next_line.o get_next_line_utils.o
	$(CC) ../srcs/main.c get_next_line.a -o ../srcs/do
