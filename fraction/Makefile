CC = gcc
AR = ar
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
ARFLAGS = rcs
LDFLAGS = -lstdc++
OUT = libfraction.a
OBJDIR = obj
BUILDDIR = build

all: directories $(OUT)

directories: $(OBJDIR) $(BUILDDIR)

test: $(OUT)
	$(CC) -c tests.cpp $(CXXFLAGS) -o $(OBJDIR)\tests.o
	$(CC) $(OBJDIR)/tests.o $(OBJDIR)/fraction.o -o $(BUILDDIR)/tests $(LDFLAGS)
	$(BUILDDIR)/tests

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT):  fraction.o
	$(AR) $(ARFLAGS) $(BUILDDIR)/$(OUT) $(OBJDIR)/fraction.o


fraction.o: fraction.cpp
	$(CC) -c fraction.cpp $(CXXFLAGS) -o $(OBJDIR)/fraction.o
