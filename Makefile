TARGET = computor

CC = clang++ -std=c++11

CFLAGS = -Wall -Werror -Wextra

I = -I include

SP = ./src/

SRC = $(SP)main.cpp\
	  $(SP)LexerClass.cpp\
	  $(SP)TermClass.cpp\
	  $(SP)ComputorClass.cpp

all : $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(I) $(SRC) -o $(TARGET)

clean :
	@rm -rf $(TARGET)

re : clean all

test : re
	@./$(TARGET) "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
