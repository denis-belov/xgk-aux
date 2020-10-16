NAME=xgk-aux

BUILD_TYPE=gnu-x64

ROOT=~

DIR=$(ROOT)/reps/denis-belov/$(NAME)

SRC=$(DIR)/src

BUILD=$(DIR)/build/$(BUILD_TYPE)

ASSEMBLER=gcc

ASSEMBLER_ARG=-c -o # trailing space

COMPILER=g++

COMPILER_ARG=\
	-c \
	-m64 -msse3 -Ofast -funroll-loops \
	-I $(SRC) \
	-o # trailing space

BUILDER=ld

BUILDER_ARG=-r -flto -o # trailing space

#file extensions
a=a
o=o
s=s

makeBuild=echo mkdir -p $(DIR)/build && mkdir -p $(BUILD)
makeA=mkdir -p $(BUILD)/$(a)
makeO=mkdir -p $(BUILD)/$(o)
makeS=mkdir -p $(BUILD)/$(s)



$(BUILD)/$(a)/$(NAME).$(a) :\
$(BUILD)/$(o)/transition.$(o) \
$(BUILD)/$(o)/transition-stack.$(o)
	$(makeBuild) && $(makeA) &&	$(makeS) && \
	$(BUILDER) \
		$(BUILD)/$(o)/transition.$(o) \
		$(BUILD)/$(o)/transition-stack.$(o) \
	$(BUILDER_ARG)$(BUILD)/$(a)/$(NAME).$(a) && \
	objdump -d -M intel -S $(BUILD)/$(a)/$(NAME).$(a) > $(BUILD)/s/$(NAME).s



$(BUILD)/$(o)/transition.$(o) :\
$(SRC)/transition-stack/transition-stack.h \
$(SRC)/transition/transition.h \
$(SRC)/transition/transition.cpp
	$(makeBuild) && $(makeO) && $(makeS) && \
	$(COMPILER) $(SRC)/transition/transition.cpp $(COMPILER_ARG)$(BUILD)/$(o)/transition.$(o) && \
	objdump -d -M intel -S $(BUILD)/$(o)/transition.$(o) > $(BUILD)/s/transition.s



$(BUILD)/$(o)/transition-stack.$(o) :\
$(SRC)/transition/transition.h \
$(SRC)/transition-stack/transition-stack.h \
$(SRC)/transition-stack/transition-stack.cpp
	$(makeBuild) && $(makeO) && $(makeS) && \
	$(COMPILER) $(SRC)/transition-stack/transition-stack.cpp $(COMPILER_ARG)$(BUILD)/$(o)/transition-stack.$(o) && \
	objdump -d -M intel -S $(BUILD)/$(o)/transition-stack.$(o) > $(BUILD)/s/transition-stack.s
