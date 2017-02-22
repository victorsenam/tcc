CXXFLAGS += -std=c++11 -Wall -Wextra -g

NAMES = algorithms/smawk lib/point lib/graham
TESTS = $(addsuffix .test,$(NAMES))

.PHONY: tests clean

tests : $(TESTS)

clean :
	rm -f $(TESTS)

algorithms/smawk.test : algorithms/smawk.test.cpp algorithms/smawk.cpp algorithms/smawk.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@

lib/point.test : lib/point.test.cpp lib/point.cpp lib/point.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@

lib/graham.test : lib/graham.test.cpp lib/graham.cpp lib/graham.h lib/point.cpp lib/point.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@
