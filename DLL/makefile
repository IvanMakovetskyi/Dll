# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable name
TARGET = main

# Source files
SRCS = main.cpp DoublyLinkedList.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Dependency files
DEPS = $(SRCS:.cpp=.d)

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to generate dependency files
%.d: %.cpp
	$(CXX) -M $(CXXFLAGS) $< > $@

# Include dependency files if they exist
-include $(DEPS)

# Run rule
run:
	./$(TARGET)

# Clean rule (deletes object files, dependency files, and executable)
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)