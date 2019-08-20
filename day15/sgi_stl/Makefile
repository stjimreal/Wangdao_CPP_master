SRCS:=$(wildcard ./src/*.cc)
ELFS:= ${patsubst ./src/%.cc, %, $(SRCS)}
CFLAGS:= -std=c++17 -Wall
CXX:= g++

all:$(ELFS)

%:./src/%.cc
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean rebuild
clean:
	rm -rf $(ELFS) $(OBJS)
rebuild:clean $(ELFS)