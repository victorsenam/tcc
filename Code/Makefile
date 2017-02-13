CXXFLAGS += -std=c++11 -Wall -Wextra -g

NAMES = algorithms/smawk
TESTS = $(addsuffix .test,$(NAMES))

.PHONY: tests clean

tests : $(TESTS)

clean :
	rm -f $(TESTS)

$(TESTS) : %.test : %.test.cpp %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
