##
##	[Makefile]
##	Created by Micael Levi on 04/08/2017
##	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
##

RM  := rm -rf
CXX      := g++ -std=c++11 -w
CPPFLAGS := -I ./headers
LDLIBS := -lm
EXEC := teste
SRCS := testes.cc ordenacaoAnalytics.cc
OBJS := $(SRCS:.cc=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

test: all
	./$(EXEC)

# .cpp.o:
# 	$(CXX) $(CPPFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(EXEC)

#\
	$@ name of the target\
	$^ name of all prerequisites with duplicates removed\
	$< name of the first prerequisite
