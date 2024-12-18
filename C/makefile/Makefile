
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -g
CRELEASE_FLAGS = -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

DEBUG = gdb
VLG = valgrind --leak-check=yes --track-origins=yes

SRC = *.c #main.c foo.c

fooer.out : $(SRC)
	@echo "Compile executable"
	$(CC) $(CFLAGS) -o fooer.out $(SRC)

$(SRC) : foo.h


run:
	./fooer.out

files: $(SRC) foo.h
	gedit $(SRC) foo.h &
	

foo.o : foo.h
	$(CC) $(CFLAGS) -c foo.c


release : $(SRC)
	@echo "Compile release executable"
	$(CC) $(CRELEASE_FLAGS) -o fooer_release.out $(SRC)
	
$(SRC) : foo.h
.PHONY : release


debug : 
	$(DEBUG) ./fooer.out
.PHONY : debug


vlg :
	$(VLG) ./fooer.out


all : fooer.out foo.o release clean
	@echo "Run all makefile commands"
.PHONY : all


clean : 
	@echo "Clean all object and executable files"
	rm fooer.out foo.o fooer_release.out
.PHONY : clean



