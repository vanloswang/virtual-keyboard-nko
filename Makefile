# Kaïraba Cissé <ckairaba@gmail.com>

# directories
SRC_PATH = $(shell pwd)/src
OBJ_PATH = ${SRC_PATH}
BIN_PATH = $(shell pwd)/bin
PIC_PATH = $(shell pwd)/pictures
INC_DIRS = -I.
# compiler
CPP = g++
# ressource compiler
RC = windres
# warnings
WARNS = -Wall
# options
WINDOWS_8 = -D _WINDOWS_8 
CPPFLAGS = -O3 -D UNICODE -D _UNICODE  ${WARNS}
LDFLAGS = -s -lcomctl32 -Wl,--subsystem,windows -lgdi32 -lm

# sources
SOURCES = ${wildcard ${SRC_PATH}/*.cpp}

OBJECTS = ${patsubst ${SRC_PATH}/%.cpp, ${OBJ_PATH}/%.o, ${SOURCES}} 

# excutable
EXECUTABLE = virtual-keyboard-nko

all : $(EXECUTABLE)

$(EXECUTABLE) : src/KResource.o ${OBJECTS}
	$(CPP)  $^ -o $(BIN_PATH)/$(EXECUTABLE) -mwindows -static $(CPPFLAGS) $(LDFLAGS) $(WINDOWS_8)

src/KResource.o : src/KResource.rc src/KApplication.manifest src/KResource.hpp
	${RC} -I.  -i $< -o $@

${OBJ_PATH}/%.o : ${SRC_PATH}/%.cpp src/KResource.hpp
	$(CPP) $(CPPFLAGS) $(WINDOWS_8) ${INC_DIRS} -c $< -o $@


clean :
	rm -rf $(OBJ_PATH)/*.o  $(BIN_PATH)/*.exe



