PROBS = A B C D E F G H I J K

all : $(PROBS)

$(PROBS) : %: %.cpp
	g++ -ggdb -o $@ $@.cpp

$(PROBS:=.cpp) : | template.cpp
	cp template.cpp $@

clean :
	rm $(PROBS)
