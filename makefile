CC			= g++
FLAGS		= -W -Wall -Werror -g -std=c++11
BIN			= bin
SRC			= $(shell find src -name '*.cpp')
OBJ			= $(patsubst src/%.cpp, bin/%.o, $(SRC))
LIBS		= m SDL2 GL GLU GLEW SOIL
INC_PATH    = $(shell find include -type d)
INCLUDE		= $(patsubst %, -I%, $(INC_PATH))
LIBRARIES	= $(patsubst %, -l%, $(LIBS))
TARGET		= $(BIN)/exe


.PHONY: all multi clean re run leak gdb folder archi

multi:
	@$(MAKE) -j all

all: $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) -o $(TARGET) -L./lib/
	@echo "\e[39mBuilding \e[1m$(TARGET)\e[0m"

archi:
	@for folder in `ls ./src`; \
	do \
		mkdir "./bin/$$folder"; \
		mkdir "./include/$$folder"; \
		for subfolder1 in `ls ./src/$$folder`; \
		do \
			mkdir "./bin/$$folder/$$subfolder1"; \
			mkdir "./include/$$folder/$$subfolder1"; \
		done;\
	done;


folder:
	@if  [ ! -d "./bin" ]; then \
		echo "Building bin folder"; \
		mkdir bin; \
	fi;
	@if  [ ! -d "./src" ]; then \
		echo "Building src folder"; \
		mkdir src; \
	fi;
	@if  [ ! -d "./include" ]; then \
		echo "Building include folder"; \
		mkdir include; \
	fi;
	@if  [ ! -d "./resources" ]; then \
		echo "Building resources folder"; \
		mkdir resources; \
	fi;
	@echo "\e[1;4mAll folders has been build\e[0m"

bin/%.o: src/%.cpp
	@$(CC) $(FLAGS) $^ -c $(LIBRARIES) $(INCLUDE) -o $@
	@echo "\e[39mCompiling \e[34m$^\e[39m"

clean:
	@rm -rf $(OBJ) $(TARGET)
	@echo "\e[31mDelete binary files\e[0m"

re: clean multi run

run: multi
	@echo "\t\e[1;4mExecuting $(TARGET)\e[0m\n"
	@./$(TARGET)

leak: all
	@echo "\e[92mLoading Valgrind on \e[1m$(TARGET)\e[0;39m\n"
	@valgrind --leak-check=full ./$(TARGET)

gdb: all
	@echo "\e[92mLoading GDB on \e[1m$(TARGET)\e[0;39m\n"
	@gdb ./$(TARGET)
