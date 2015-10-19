CC ?= icc
CXX ?= icpc

CFLAGS ?= -std=c11 -g -O2 -Wall -Wextra
CXXFLAGS ?= -std=c++11 -g -O2 -Wall -Wextra


all: singlylist

%: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

%: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

