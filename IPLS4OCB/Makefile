PROBS = A B C D E F G H I J K

all : $(PROBS)

$(PROBS) : %: %.cpp
	g++ -std=c++11 -ggdb -o $@ $@.cpp

$(PROBS:=.cpp) : | template.cpp
	cp template.cpp $@

clean :
	rm $(PROBS)
