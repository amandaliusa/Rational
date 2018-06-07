CXXFLAGS = -Wall -Werror -std=c++14
TEST-RATIONAL_OBJS = rational.o testbase.o test-rational.o

all: test-rational

test-rational: $(TEST-RATIONAL_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: all
	./test-rational

clean:
	rm -f test-rational *.o *~

.PHONY: all clean test
