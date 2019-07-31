SRCS:=$(wildcard ./src/*.cc)
OBJS := ${patsubst ./src/%.cc, ./bin/%.o, $(SRCS)}
ELFS:= singleton
CFLAGS:= -Wall
CXX:= g++
$(ELFS):$(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@ -llog4cpp -lpthread
./bin/%.o:./src/%.cc
	$(CXX) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(ELFS) $(OBJS)
.PHONY: rebuild
rebuild:clean $(ELFS)