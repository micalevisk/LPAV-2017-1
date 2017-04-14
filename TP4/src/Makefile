##
##	[Makefile]
##	Created by Micael Levi on 04/08/2017
##	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
##

RM := rm -rf
CXX := g++
CPPFLAGS := -std=c++11 -w -I ./headers -I ./headers/lib
LDLIBS := -lm
SRCS_ALGORITMOS := $(addsuffix .cc, $(addprefix algoritmos/, bubblesort selectionsort insertionsort mergesort quicksort heapsort) )
SRCS := $(addsuffix .cc, main ordenacaoAnalytics) $(SRCS_ALGORITMOS)
OBJS := $(SRCS:.cc=.o)
EXEC := tp4_sort


##########################################
ifneq ($(origin PRECISION), undefined)
	CPPFLAGS += -D PRECISION=$(PRECISION)
endif
ifeq ($(VERBOSE), true)
	CPPFLAGS += -D VERBOSE
endif
ifeq ($(MILLISECONDS), true)
	CPPFLAGS += -D MILLISECONDS
endif
ifeq ($(DEBUG), true)
	CPPFLAGS += -D DEBUG
endif
##########################################

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

test: clean all
	./$(EXEC)

clean:
	$(RM) $(OBJS) $(EXEC)

mostlyclean:
	$(RM) $(OBJS)
