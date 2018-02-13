PROBS = A B C D E F G H I J K

all : $(PROBS)
$(PROBS): %: %.cpp
	clang++ -ggdb -std=c++11 -o $@ $@.cpp

