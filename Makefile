MAIN_FILE = main.cpp

LIBRARY_FILE = directory_tree.cpp

all: program

program: main.cpp
	g++ -c $(LIBRARY_FILE) -o directory_tree.o
	ar rcs libdirectory_tree.a directory_tree.o
	g++ $(MAIN_FILE) -o program libdirectory_tree.a

clean:
	rm -f main.cpp program