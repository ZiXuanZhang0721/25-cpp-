CXX = g++
CXXFLAGS = -g -Wall
TARGET = main
SRCS = main.cpp Decision.cpp Student.cpp Group.cpp Weather.cpp World.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean