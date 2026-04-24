CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g
LDFLAGS := -lncurses

# 可执行程序名称
TARGET := project9

# 所有源文件（.cpp）
SRCS := \
    Grass.cpp \
    Gui.cpp \
    Rabbit.cpp \
    Tiger.cpp \
    Wolf.cpp \
    main.cpp

# 所有目标文件（.o）
OBJS := $(SRCS:.cpp=.o)

# 默认目标：生成可执行文件
all: $(TARGET)

# 链接目标文件生成可执行程序
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# 模式规则：编译 .cpp 为 .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 声明伪目标
.PHONY: all clean