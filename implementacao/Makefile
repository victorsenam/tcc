CXXFLAGS += -std=c++11 -Wall -Wextra -g -fdiagnostics-color

NAMES = algoritmos/smawk lib/point lib/graham
TESTS = $(addsuffix .test,$(NAMES))

.PHONY: tests clean

tests : $(TESTS)

clean :
	rm -f $(TESTS)

algoritmos/smawk.test : algoritmos/smawk.test.cpp algoritmos/smawk.cpp algoritmos/smawk.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@

lib/point.test : lib/point.test.cpp lib/point.cpp lib/point.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@

lib/graham.test : lib/graham.test.cpp lib/graham.cpp lib/graham.h lib/point.cpp lib/point.h lib/test_helpers.cpp lib/test_helpers.h
	$(CXX) $(CXXFLAGS) $^ -o $@
