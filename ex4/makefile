
TARGET	=	program
CC	= g++
CFLAGS	= 

default: $(TARGET)

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
		$(CC) $(CFLAGS) -cpp $< -o $@


$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@