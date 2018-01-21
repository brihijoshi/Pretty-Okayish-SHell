CC=gcc
FLAGS = -o
OBJ = ./posh_bin/posh_cat ./posh_bin/posh_date ./posh_bin/posh_ls ./posh_bin/posh_mkdir ./posh_bin/posh_rm posh.c
ALL = ./posh_bin/posh_cat ./posh_bin/posh_date ./posh_bin/posh_ls ./posh_bin/posh_mkdir ./posh_bin/posh_rm posh

all: $(ALL)

./posh_bin/posh_cat: ./posh_bin/cat.c
	gcc $(FLAGS) ./posh_bin/posh_cat ./posh_bin/cat.c

./posh_bin/posh_date: ./posh_bin/date.c
	gcc $(FLAGS) ./posh_bin/posh_date ./posh_bin/date.c

./posh_bin/posh_ls: ./posh_bin/ls.c
	gcc $(FLAGS) ./posh_bin/posh_ls ./posh_bin/ls.c

./posh_bin/posh_mkdir: ./posh_bin/mkdir.c
	gcc $(FLAGS) ./posh_bin/posh_mkdir ./posh_bin/mkdir.c

./posh_bin/posh_rm: ./posh_bin/rm.c
	gcc $(FLAGS) ./posh_bin/posh_rm ./posh_bin/rm.c

posh: $(OBJ)
	gcc $(FLAGS) posh posh.c

.PHONY: clean

clean:
	rm -rf *.o $(ALL)
