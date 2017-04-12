##
##	[Makefile]
##	Created by Micael Levi on 04/08/2017
##	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
##
## https://www.gnu.org/savannah-checkouts/gnu/make/manual/html_node/File-Name-Functions.html#index-addsuffix-591

RM := rm -rf
CXX := g++
CPPFLAGS := -std=c++11 -w -I ./headers -I ./headers/lib -I./
LDLIBS := -lm
SRCS_ALGORITMOS := $(addsuffix .cc, $(addprefix algoritmos/, bubblesort selectionsort insertionsort mergesort quicksort heapsort) )
SRCS := $(addsuffix .cc, main ordenacaoAnalytics) $(SRCS_ALGORITMOS)
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
ifneq ($(origin DESCENDING), undefined)
	CPPFLAGS += -D DESCENDING
endif
ifneq ($(origin MILLISECONDS), undefined)
	CPPFLAGS += -D MILLISECONDS
endif
ifneq ($(origin DEBUG), undefined)
	CPPFLAGS += -D DEBUG
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
