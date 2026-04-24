CXX = g++
CXXSTD = -std=c++11

# 调试模式标志
DEBUG_FLAGS = -g -DDEBUG -O0
RELEASE_FLAGS = -O2 -DNDEBUG

# 默认使用调试模式
CXXFLAGS = $(CXXSTD) -Wall -Wextra -pedantic $(DEBUG_FLAGS)

# 目标可执行文件
TARGET = project6

# 源文件和头文件
SRCS = main.cpp World.cpp Group.cpp Student.cpp StudentVector.cpp Weather.cpp Decision.cpp
HEADERS = World.h Group.h Student.h StudentVector.h Weather.h Decision.h

# 对象文件
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# 包含依赖关系
-include $(DEPS)

# 编译规则，同时生成依赖关系
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

# 深度清理
distclean: clean
	rm -f *~ *.bak *.tmp

# 重新构建
rebuild: distclean all

# 运行
run: $(TARGET)
	./$(TARGET)

# Valgrind内存检查
