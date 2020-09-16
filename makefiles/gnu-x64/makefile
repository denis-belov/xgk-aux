DIR=~/reps/denis-belov/xgk

SRC=$(DIR)/src

BUILD=$(DIR)/build/gnu-x64

COMP_ARGS= \
	-c \
	-m64 -msse3 -Ofast -funroll-loops \
	-I $(SRC) \
	-D MEM_ADDR_LENGTH=8 -D XGK_NO_INLINE=1



$(BUILD)/a/xgk.a : \
$(BUILD)/o/util-asm-x64.o \
$(BUILD)/o/util.o \
$(BUILD)/o/vec4.o \
$(BUILD)/o/vec4-32.o \
$(BUILD)/o/vec4-128.o \
$(BUILD)/o/quat.o \
$(BUILD)/o/quat-32.o \
$(BUILD)/o/quat-128.o \
$(BUILD)/o/mat4.o \
$(BUILD)/o/mat4-32.o \
$(BUILD)/o/mat4-128.o\
$(BUILD)/o/object.o
	ld -o $(BUILD)/a/xgk.a \
	-r \
	-flto \
	$(BUILD)/o/util-asm-x64.o \
	$(BUILD)/o/util.o \
	$(BUILD)/o/vec4.o \
	$(BUILD)/o/vec4-32.o \
	$(BUILD)/o/vec4-128.o \
	$(BUILD)/o/quat.o \
	$(BUILD)/o/quat-32.o \
	$(BUILD)/o/quat-128.o \
	$(BUILD)/o/mat4.o \
	$(BUILD)/o/mat4-32.o \
	$(BUILD)/o/mat4-128.o \
	$(BUILD)/o/object.o



$(BUILD)/o/util-asm-x64.o : $(SRC)/util/util-asm-x64.s
	gcc -o $(BUILD)/o/util-asm-x64.o \
	-c \
	$(SRC)/util/util-asm-x64.s



$(BUILD)/o/util.o : $(SRC)/util/util.cpp
	g++ -o $(BUILD)/o/util.o \
	$(SRC)/util/util.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4.o : $(SRC)/data/vec4/vec4.cpp
	g++ -o $(BUILD)/o/vec4.o \
	$(SRC)/data/vec4/vec4.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4-32.o : $(SRC)/data/vec4/vec4-32.cpp
	g++ -o $(BUILD)/o/vec4-32.o \
	$(SRC)/data/vec4/vec4-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4-128.o : $(SRC)/data/vec4/vec4-128.cpp
	g++ -o $(BUILD)/o/vec4-128.o \
	$(SRC)/data/vec4/vec4-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat.o : $(SRC)/data/quat/quat.cpp
	g++ -o $(BUILD)/o/quat.o \
	$(SRC)/data/quat/quat.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat-32.o : $(SRC)/data/quat/quat-32.cpp
	g++ -o $(BUILD)/o/quat-32.o \
	$(SRC)/data/quat/quat-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat-128.o : $(SRC)/data/quat/quat-128.cpp
	g++ -o $(BUILD)/o/quat-128.o \
	$(SRC)/data/quat/quat-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4.o : $(SRC)/data/mat4/mat4.cpp
	g++ -o $(BUILD)/o/mat4.o \
	$(SRC)/data/mat4/mat4.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4-32.o : $(SRC)/data/mat4/mat4-32.cpp
	g++ -o $(BUILD)/o/mat4-32.o \
	$(SRC)/data/mat4/mat4-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4-128.o : $(SRC)/data/mat4/mat4-128.cpp
	g++ -o $(BUILD)/o/mat4-128.o \
	$(SRC)/data/mat4/mat4-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/object.o : $(SRC)/data/data.h $(SRC)/object/object.h $(SRC)/object/object.cpp
	g++ -o $(BUILD)/o/object.o \
	$(SRC)/object/object.cpp \
	$(COMP_ARGS)
