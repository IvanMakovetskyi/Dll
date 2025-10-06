# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable name
TARGET = main

# Source files
SRCS = main.cpp DoublyLinkedList.cpp Node.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Clean rule (deletes object files and executable)
clean:
	rm -f $(OBJS) $(TARGET)