SOURCES := $(wildcard *.cpp)
# Objs are all the sources, with .cpp replaced by .o

OUT = ../lang/dl
CC = g++
ODIR = .build
SDIR = 
CXXFLAGS = -std=c++14

_OBJS := $(SOURCES:.cpp=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: %.cpp 
	$(CC) -c $(CXXFLAGS) -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS) 
	$(CC) $(LDFLAGS) -o $(OUT) $(OBJS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)