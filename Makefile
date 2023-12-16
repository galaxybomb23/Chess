CC = g++
CFLAGS = std=c++20 -Wall -Wextra -pedantic -g
DFLAGS =

# Directory containing header files
INCDIR = include

# Directory containing source files
SRCDIR = src

# Source and object files
SRC = $(SRCDIR)/main.cpp
OBJ = $(SRC:.cpp=.o)

#Include files
INC = $(INCDIR)/


# Compiler flags
CFLAGS = -I$(INCDIR) -Wall

# Rule to compile everything
all: $(OBJ)
	# @clear
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o main $(OBJ)
	@echo "Running..."
	@./main
	@echo "Cleaning up..."
	@rm -f $(OBJ) main

# Rule to compile source files to object files
$(OBJ): $(SRC) $(INC)
	@$(CC) $(INC) $(CFLAGS) -c $< -o $@

# Rule to clean up object and executable files
clean:
	rm -f $(OBJ) main

# Rule to run the program
run:
	@echo "Running..."
	@./main

