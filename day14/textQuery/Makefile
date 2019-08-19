SRCS:=$(wildcard ./src/*.cc)
OBJS := ${patsubst ./src/%.cc, ./bin/%.o, $(SRCS)}
ELFS:= textQuery
CFLAGS:= -std=c++17 -Wall
CXX:= g++

$(ELFS):$(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@

./bin/%.o:./src/%.cc
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean rebuild
clean:
	rm -rf $(ELFS) $(OBJS)
rebuild:clean $(ELFS)