%.cpp : | template.cpp
	cp template.cpp $@

%: %.cpp
	g++ -ggdb -o $@ $@.cpp

clean :
	mkdir ../temp
	mv *.* ../temp
	mv Makefile ../temp
	rm -f *
	mv ../temp/* .
	rmdir ../temp
