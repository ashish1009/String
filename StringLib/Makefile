GCC = g++
CPP = c++17

STRING_SRC = StringClass/Src/
STRING_INC = StringClass/Inc/

SRC = Main.cpp
SRC+= $(STRING_SRC)StringClass.cpp
SRC+= $(STRING_SRC)PrivateStringClass.cpp
SRC+= $(STRING_SRC)Common.cpp
SRC+= $(STRING_SRC)Constructors.cpp
SRC+= $(STRING_SRC)Modifiers.cpp
SRC+= $(STRING_SRC)StringOperation.cpp
SRC+= $(STRING_SRC)StringIterator.cpp

SRC+= $(STRING_SRC)Iterator.cpp

INC = -I$(STRING_INC)

OBJ = String.out

default:
	$(GCC) -g -std=$(CPP) $(SRC) $(INC) -o$(OBJ) 
