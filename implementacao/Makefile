CXXFLAGS += -std=c++11 -Wall -Wextra -fdiagnostics-color

exemplos/ExemploMonge/ExemploMonge.SMAWK.out : %.out : %.cpp algoritmos/SMAWK.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $+ -o $@

exemplos/ExemploMonge/ExemploMonge.DivConq.out : %.out : %.cpp algoritmos/DivConq.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $+ -o $@

exemplos/ExemploMonge/ExemploMonge.Trivial.out : %.out : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $+ -o $@
