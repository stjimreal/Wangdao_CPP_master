SRCS:=$(wildcard ./src/*.cc)
OBJS := ${patsubst ./src/%.cc, ./bin/%.o, $(SRCS)}
ELFS:= ${patsubst ./src/%.cc, %, $(SRCS)}
CFLAGS:= -Wall
CXX:= g++
all:$(ELFS)
%:./src/%.cc
	$(CXX) $(CFLAGS) $< -o $@ 

.PHONY: clean
clean:
	rm -rf $(ELFS) $(OBJS)
.PHONY: rebuild
rebuild:clean $(ELFS)