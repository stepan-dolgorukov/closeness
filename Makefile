CXX := g++

closeness: closeness.o
	${CXX} $^ -o $@

closeness.o: closeness.cc
	${CXX} -c $^ -o $@
