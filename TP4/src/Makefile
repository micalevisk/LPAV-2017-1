##
##	[Makefile]
##	Created by Micael Levi on 04/08/2017
##	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
##

RM := rm -rf
CXX := g++
CPPFLAGS := -std=c++11 -w -I ./headers -I ./headers/lib -I./
LDLIBS := -lm
SRCS := main.cc ordenacaoAnalytics.cc algoritmos/bubblesort.cc algoritmos/selectionsort.cc
OBJS := $(SRCS:.cc=.o)
EXEC := teste


##########################################
ifneq ($(origin PRECISION), undefined)
	CPPFLAGS += -D PRECISION=$(PRECISION)
endif
ifneq ($(origin TIPO), undefined)
	CPPFLAGS += -D T=$(TIPO)
endif
ifneq ($(origin VERBOSE), undefined)
	CPPFLAGS += -D VERBOSE
endif
ifneq ($(origin DECRESCENTE), undefined)
	CPPFLAGS += -D DECRESCENTE
endif
##########################################

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

test: clean all
	./$(EXEC)

# .cpp.o:
# 	$(CXX) $(CPPFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(EXEC)

mostlyclean:
	$(RM) $(OBJS)

#\
	$@ name of the target\
	$^ name of all prerequisites with duplicates removed\
	$< name of the first prerequisite
