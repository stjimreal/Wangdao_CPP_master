SRCS:=$(wildcard ./src/*.cc)
ELFS:= ${patsubst ./src/%.cc, %, $(SRCS)}
CFLAGS:= -Wall
CXX:= g++
all:$(ELFS)#必须要加

%:./src/%.cc
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean rebuild
clean:
	rm -rf $(ELFS) $(OBJS)
rebuild:clean $(ELFS)