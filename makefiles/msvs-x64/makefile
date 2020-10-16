NAME=xgk-aux

BUILD_TYPE=gnu-x64

ROOT=C:

DIR=$(ROOT)/reps/denis-belov/$(NAME)

SRC=$(DIR)/src

BUILD=$(DIR)/build/$(BUILD_TYPE)

ASSEMBLER=ml64

ASSEMBLER_ARG=/Fo

COMPILER=cl

COMPILER_ARG=\
  /c /EHsc /MP999 /std:c++17 \
  /O2 \
  /I$(SRC) \
  /Fo

BUILDER=lib

BUILDER_ARG=/SUBSYSTEM:CONSOLE /OUT:

#file extensions
a=lib
o=obj
s=asm

makeBuild=(IF NOT EXIST $(DIR)/build cd /d $(DIR) && mkdir build) && (IF NOT EXIST $(BUILD) cd /d $(DIR)/build && mkdir $(BUILD_TYPE))
makeA=(IF NOT EXIST $(BUILD)/lib cd /d $(BUILD) && mkdir lib)
makeO=(IF NOT EXIST $(BUILD)/obj cd /d $(BUILD) && mkdir obj)
makeS=(IF NOT EXIST $(BUILD)/asm cd /d $(BUILD) && mkdir asm)



$(BUILD)/$(a)/$(NAME).$(a) :\
$(BUILD)/$(o)/transition.$(o) \
$(BUILD)/$(o)/transition-stack.$(o)
  $(makeBuild) && $(makeA) &&	$(makeS) && \
  $(BUILDER) \
    $(BUILD)/$(o)/transition.$(o) \
    $(BUILD)/$(o)/transition-stack.$(o) \
  $(BUILDER_ARG)$(BUILD)/$(a)/$(NAME).$(a) \
  && dumpbin /disasm $(BUILD)/$(a)/$(NAME)$(a) /out:$(BUILD)/$(s)/$(NAME).$(s)



$(BUILD)/$(o)/const.$(o) :\
$(SRC)/transition-stack/transition-stack.h \
$(SRC)/transition/transition.h \
$(SRC)/transition/transition.cpp
  $(makeBuild) && $(makeO) &&	$(makeS) && \
  $(COMPILER) $(SRC)/transition/transition.cpp $(COMPILER_ARG)$(BUILD)/$(o)/transition.$(o) \
  /FA /Fa$(BUILD)/$(s)/transition.$(s)



$(BUILD)/$(o)/transition-stack.$(o) :\
$(SRC)/transition/transition.h \
$(SRC)/transition-stack/transition-stack.h \
$(SRC)/transition-stack/transition-stack.cpp
  $(makeBuild) && $(makeO) && $(makeS) && \
  $(COMPILER) $(SRC)/transition-stack/transition-stack.cpp $(COMPILER_ARG)$(BUILD)/$(o)/transition-stack.$(o) && \
  /FA /Fa$(BUILD)/$(s)/transition-stack.$(s)
