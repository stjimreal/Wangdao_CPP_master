SRCS:=$(wildcard ./src/*.cc)
OBJS := ${patsubst ./src/%.cc, ./bin/%.o, $(SRCS)}
ELFS:= queue
CFLAGS:= -Wall
CXX:= g++-9
$(ELFS):$(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@
./bin/%.o:./src/%.cc
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(ELFS) $(OBJS)
.PHONY: rebuild
rebuild:clean $(ELFS)