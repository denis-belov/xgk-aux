DIR=~/reps/denis-belov/xgk-aux

SRC=$(DIR)/src

BUILD=$(DIR)/build/emcc

COMP_ARGS= \
	-c \
	-O3 \
	-I $(SRC) \
	-D MEM_ADDR_LENGTH=8 -D XGK_NO_INLINE=1



$(BUILD)/a/xgk-aux.a : \
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
	mkdir -p $(BUILD) && mkdir -p $(BUILD)/a && \
	emcc -o $(BUILD)/a/xgk-aux.a \
	-r \
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



$(BUILD)/o/util.o : $(SRC)/util/util.cpp
	emcc -o $(BUILD)/o/util.o \
	$(SRC)/util/util.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4.o : $(SRC)/data/vec4/vec4.cpp
	emcc -o $(BUILD)/o/vec4.o \
	$(SRC)/data/vec4/vec4.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4-32.o : $(SRC)/data/vec4/vec4-32.cpp
	emcc -o $(BUILD)/o/vec4-32.o \
	$(SRC)/data/vec4/vec4-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/vec4-128.o : $(SRC)/data/vec4/vec4-128.cpp
	emcc -o $(BUILD)/o/vec4-128.o \
	$(SRC)/data/vec4/vec4-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat.o : $(SRC)/data/quat/quat.cpp
	emcc -o $(BUILD)/o/quat.o \
	$(SRC)/data/quat/quat.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat-32.o : $(SRC)/data/quat/quat-32.cpp
	emcc -o $(BUILD)/o/quat-32.o \
	$(SRC)/data/quat/quat-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/quat-128.o : $(SRC)/data/quat/quat-128.cpp
	emcc -o $(BUILD)/o/quat-128.o \
	$(SRC)/data/quat/quat-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4.o : $(SRC)/data/mat4/mat4.cpp
	emcc -o $(BUILD)/o/mat4.o \
	$(SRC)/data/mat4/mat4.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4-32.o : $(SRC)/data/mat4/mat4-32.cpp
	emcc -o $(BUILD)/o/mat4-32.o \
	$(SRC)/data/mat4/mat4-32.cpp \
	$(COMP_ARGS)



$(BUILD)/o/mat4-128.o : $(SRC)/data/mat4/mat4-128.cpp
	emcc -o $(BUILD)/o/mat4-128.o \
	$(SRC)/data/mat4/mat4-128.cpp \
	$(COMP_ARGS)



$(BUILD)/o/object.o : $(SRC)/data/data.h $(SRC)/object/object.h $(SRC)/object/object.cpp
	emcc -o $(BUILD)/o/object.o \
	$(SRC)/object/object.cpp \
	$(COMP_ARGS)
