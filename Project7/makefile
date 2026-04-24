CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
TARGET = Project7

$(TARGET): main.C Bigint.C Bigint.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.C Bigint.C

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run