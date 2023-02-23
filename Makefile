CC = gcc
CFLAGS = -g -Wall
DRIVER_PROGS_DIR = ./driver_progs
ABSTRACT_ARRAY_DIR = ./abstract_array
OBJS_DIR = ./objs
INCL_FLAGS = -I $(ABSTRACT_ARRAY_DIR)
OBJ1 = $(OBJS_DIR)/abstract_array.o
OBJ2 = $(OBJS_DIR)/main_int.o
OBJS1 = $(OBJ1) $(OBJ2)
OBJ3 = $(OBJS_DIR)/main_double.o
OBJS2 = $(OBJ1) $(OBJ3)
OBJ4 = $(OBJS_DIR)/main_array.o
CFILE1 = $(ABSTRACT_ARRAY_DIR)/abstract_array.c
CFILE2 = $(DRIVER_PROGS_DIR)/main_int.c
CFILE3 = $(DRIVER_PROGS_DIR)/main_double.c
PROG1 = runmain_int
PROG2 = runmain_double
PROGS = $(PROG1) $(PROG2) $(PROG3)

all: $(PROGS)
$(PROG1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(PROG1) $(OBJS1)
$(PROG2): $(OBJS2)
	$(CC) $(CFLAGS) -o $(PROG2) $(OBJS2)
$(OBJ1): $(CFILE1) 
	$(CC) $(CFLAGS) -c $(CFILE1) $(INCL_FLAGS)
	mv *.o $(OBJS_DIR)
$(OBJ2): $(CFILE2)
	$(CC) $(CFLAGS) -c $(CFILE2) $(INCL_FLAGS)
	mv *.o $(OBJS_DIR)
$(OBJ3): $(CFILE3)
	$(CC) $(CFLAGS) -c $(CFILE3) $(INCL_FLAGS)
	mv *.o $(OBJS_DIR)
clean:
	rm -f $(OBJS1) $(OBJS2) $(PROGS)
