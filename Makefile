CC=gcc
FLAGS = -o
OBJ = posh_cat posh_date posh_ls posh_mkdir posh_rm posh.c
ALL = posh_cat posh_date posh_ls posh_mkdir posh_rm posh

all: $(ALL)

posh_cat: cat.c
	gcc $(FLAGS) posh_cat cat.c

posh_date: date.c
	gcc $(FLAGS) posh_date date.c

posh_ls: ls.c
	gcc $(FLAGS) posh_ls ls.c

posh_mkdir: mkdir.c
	gcc $(FLAGS) posh_mkdir mkdir.c

posh_rm: rm.c
	gcc $(FLAGS) posh_rm rm.c

posh: $(OBJ)
	gcc $(FLAGS) posh posh.c

.PHONY: clean

clean:
	rm -rf *.o $(ALL)
