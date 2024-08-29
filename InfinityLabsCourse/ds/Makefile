TARGET = none
WS =

# F - Target's folder
# I - Additional Includes' folder
# LF - Additional Linker's flags

F = ds
LF =
I =

WORKSPACE = /home/or-kol/git/
SRC = $(WORKSPACE)${F}/src/
INC = $(WORKSPACE)${F}/include/
TST = $(WORKSPACE)${F}/test/

CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Wextra -fPIC -I $(INC) -I $(WORKSPACE)${I}
LDFLAGS = -L. $(addprefix -l,$(patsubst %.o, %, $(DEPENDENCIES_OBJ))) $(LF) -Wl,-rpath=.
VLG = valgrind --leak-check=yes --track-origins=yes


ifneq ($(TARGET),none)
DEPENDENCIES = $(shell $(CC) -MM $(SRC)$(TARGET).c $(CFLAGS))
DEPENDENCIES_SRC = $(shell echo $(subst $(TARGET).o: ,,$(patsubst %.h, %.c,$(subst include,src,$(DEPENDENCIES)))))
DEPENDENCIES_OBJ = $(shell basename -a $(patsubst %.c, %.o,$(DEPENDENCIES_SRC)))
endif

DEBUG = 1
SUBLIB = 0

.PHONY: default clean cleano cleanall release debug all test help

ifeq ($(TARGET),none)
default:
	@echo invalid option
endif
ifeq ($(SUBLIB), 0)
$(TARGET).out: lib$(TARGET).so $(TARGET)_test.o
	$(CC) $(TARGET)_test.o -o $@ $(LDFLAGS)
	@echo $@ Compiled Successfuly!
endif

lib$(TARGET).so: $(DEPENDENCIES_OBJ)
	$(CC) -shared -o $@ $< $(LDFLAGS)
	@echo $@ Library File Created!
						
$(TARGET).o: $(SRC)$(TARGET).c
ifeq ($(DEBUG), 1)
	$(CC) -c $(SRC)$(TARGET).c -g $(CFLAGS) 
else
	$(CC) -c $(SRC)$(TARGET).c -DNDEBUG -O3 $(CFLAGS) 
endif
	@echo $@ Object File Created!
	
$(TARGET)_test.o: $(TST)$(TARGET)_test.c
	$(CC) -c $(TST)$(TARGET)_test.c -g $(CFLAGS) 

%.o: 
	make -s TARGET=$(patsubst %.o,%,$@) F=ds SUBLIB=1

run: 
	@echo "Run executable"
	./$(TARGET).out

vlg:
	$(VLG) ./$(TARGET).out

files:
	gedit ./include/$(TARGET).h ./src/$(TARGET).c ./test/$(TARGET)_test.c &

cleanall:
	@rm *.o *.so *.out -f
	@echo All files Removed Successfuly!

clean:
	@rm *.o *.so -f 
	@echo Object files and libraries Removed Successfuly!

cleano:
	@rm *.o -f
	@echo All Object files Removed Successfuly!

release: 
	@make -s TARGET=$(TARGET) DEBUG=0

debug: $(TARGET).out

all: release lib$(TARGET).so
	@make -s cleano






