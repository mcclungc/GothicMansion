###
### @file Makefile Connie McClung - adapted from Harlan James example posted on Canvas
### @file - intermediate_make_sample
### @author - Harlan James <waldroha@oregonstate.edu>
### @description - Intermediate example for reasonably complete Makefile
###

#
# Project Name
#
PROJ = Final_Project_McClung_Connie

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = main.cpp
SRC += Game.cpp
SRC += Armor.cpp
SRC += Attic.cpp
SRC += Being.cpp
SRC += Cellar.cpp
SRC += Ghost.cpp
SRC += GuestRoom.cpp
SRC += Helpers.cpp
SRC += Heroine.cpp
SRC += Hound.cpp
SRC += Intruder.cpp
SRC += Kitchen.cpp
SRC += Library.cpp
SRC += MasterSuite.cpp
SRC += Raven.cpp
SRC += Roof.cpp
SRC += Room.cpp
SRC += Servant.cpp
#
# Header Files
#
HEADER = Armor.hpp
HEADER += Attic.hpp
HEADER += Being.hpp
HEADER += Cellar.hpp
HEADER += Game.hpp
HEADER += Ghost.hpp
HEADER += GuestRoom.hpp
HEADER += Helpers.hpp
HEADER += Heroine.hpp
HEADER += Hound.hpp
HEADER += Intruder.hpp
HEADER += Item.hpp
HEADER += Kitchen.hpp
HEADER += Library.hpp
HEADER += LinkedList.hpp
HEADER += MasterSuite.hpp
HEADER += Raven.hpp
HEADER += Roof.hpp
HEADER += Room.hpp
HEADER += Servant.hpp
#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ).bin

#
# Compiler Flags
#
CFLAGS = -std=c++0x -Wall -pedantic-errors -g

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#
# Names of tags that aren't actually files
#
.PHONY: default debug clean zip

#
# Default Behavior:
#     1. Remove everything to start from scratch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) debug

#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ) $(HEADER)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

main: $(OBJ) 
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp *.pdf makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f main *.o $(BIN)

