CXX = g++
CXXFLAGS = -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -pipe -O2 -DNDEBUG 
LDLIBS = 
RM = rm -f

all: main

debug: CXXFLAGS += -ggdb 
debug: main

main:
	$(CXX) $(CXXFLAGS) main.cpp menu.cpp login.cpp io.cpp register.cpp -o login

clean:
	$(RM) login
