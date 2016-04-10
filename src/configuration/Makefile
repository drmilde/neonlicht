PROJECT_ROOT=./config4cpp
include $(PROJECT_ROOT)/Makefile.inc

OBJ_FILES= main.o

.PHONY: all clean clobber

all:		demo$(EXE_EXT)

demo$(EXE_EXT):	$(OBJ_FILES)
	$(CXX) -o demo$(EXE_EXT) $(OBJ_FILES) $(LINK_WITH_CONFIG4CPP)

clean:
	rm -f *.o demo$(EXE_EXT)

clobber: clean

