PROJECT_NAME = TP3 - C++
EXEC_EXE = main
SRC_PATH = ./src
DEP_PATH = ./include
LIB_PATH = ./lib
OBJ_PATH = ./obj
OPTI = 0
DEBUG =
SYNTAX = -pedantic -std=c++2a -fconcepts
WARNINGS = -Wall -Wextra
LIBRARIES = 
OBJS = $(OBJ_PATH)/main.o $(OBJ_PATH)/SolutionQueen.o

CXX = g++
CXXFLAGS = $(WARNINGS) $(SYNTAX) -O$(OPTI) $(DEBUG) -I$(DEP_PATH)
LDFLAGS = $(LIBRARIES) $(DEBUG)

.PHONY = all clean distclean

all : distclean $(EXEC_EXE)

$(EXEC_EXE) : $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

clean:
	rm -f $(OBJ_PATH)/*

distclean:
	rm -fr $(EXEC_EXE) $(OBJ_PATH)/*