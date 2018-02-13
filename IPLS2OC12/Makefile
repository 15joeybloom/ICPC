PROBS = A B C D E F G H I J

all : $(PROBS)

$(PROBS) : %: %.cpp
	g++ -ggdb --std=c++11 -o $@ $@.cpp

$(PROBS:=.cpp) : | template.cpp
	cp template.cpp $@

clean :
	rm $(PROBS)
