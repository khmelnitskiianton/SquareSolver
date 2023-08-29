CC = g++

SHELL = C:/Windows/System32/cmd.exe

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXECUTABLE = proga.exe

OBJECTS=$(SOURCES:.cpp=.o)

start: main.o comparing.o file.o in.o out.o solving.o testing.o
	$(CC) main.o comparing.o file.o in.o out.o solving.o testing.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

comparing.o: comparing.cpp
	$(CC) $(CFLAGS) comparing.cpp

in.o: in.cpp
	$(CC) $(CFLAGS) in.cpp

out.o: out.cpp
	$(CC) $(CFLAGS) out.cpp

file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp

solving.o: solving.cpp
	$(CC) $(CFLAGS) solving.cpp

testing.o: testing.cpp
	$(CC) $(CFLAGS) testing.cpp

clean:
	rm -rf *.o 

docs:
	doxygen doxy_config

run: 
	D:/Study/C/SquareSolver/$(EXECUTABLE)
