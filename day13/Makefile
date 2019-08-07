SRCS:=$(wildcard ./src/*.cc)
OBJS := ${patsubst ./src/%.cc, ./bin/%.o, $(SRCS)}
ELFS:= ${patsubst ./src/%.cc, %, $(SRCS)}
CFLAGS:= -std=c++17 -Wall
CXX:= g++
all:$(ELFS)

%:./src/%.cc
	$(CXX) $(CFLAGS) $< -o $@ -llog4cpp

.PHONY: clean rebuild
clean:
	rm -rf $(ELFS) $(OBJS)
rebuild:clean $(ELFS)