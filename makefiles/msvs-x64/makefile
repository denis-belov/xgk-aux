DIR=E:/reps/denis-belov/xgk
SRC=$(DIR)/src
BUILD=$(DIR)/build-win-x64
COMP_ARGS=/c /EHsc /MD /MP999 /O2 /I$(SRC) /DMEM_ADDR_LENGTH=8 /DXGK_NO_INLINE=1



$(BUILD)/lib/xgk.lib : \
$(BUILD)/obj/win-x64.obj \
$(BUILD)/obj/util.obj \
$(BUILD)/obj/vec4.obj \
$(BUILD)/obj/vec4-32.obj \
$(BUILD)/obj/vec4-128.obj \
$(BUILD)/obj/quat.obj \
$(BUILD)/obj/quat-32.obj \
$(BUILD)/obj/quat-128.obj \
$(BUILD)/obj/mat4.obj \
$(BUILD)/obj/mat4-32.obj \
$(BUILD)/obj/mat4-128.obj \
$(BUILD)/obj/object.obj \
$(BUILD)/obj/time.obj \
$(BUILD)/obj/orbit.obj
  lib \
  /OUT:$(BUILD)/lib/xgk.lib \
  $(BUILD)/obj/win-x64.obj \
  $(BUILD)/obj/util.obj \
  $(BUILD)/obj/vec4.obj \
  $(BUILD)/obj/vec4-32.obj \
  $(BUILD)/obj/vec4-128.obj \
  $(BUILD)/obj/quat.obj \
  $(BUILD)/obj/quat-32.obj \
  $(BUILD)/obj/quat-128.obj \
  $(BUILD)/obj/mat4.obj \
  $(BUILD)/obj/mat4-32.obj \
  $(BUILD)/obj/mat4-128.obj \
  $(BUILD)/obj/object.obj \
  $(BUILD)/obj/time.obj \
  $(BUILD)/obj/orbit.obj



$(BUILD)/obj/win-x64.obj : $(SRC)/util/win-x64.asm
  ml64 \
  /Fo$(BUILD)/obj/win-x64.obj \
  /c \
  $(SRC)/util/win-x64.asm



$(BUILD)/obj/util.obj : $(SRC)/util/util.cpp
  cl \
  $(SRC)/util/util.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/util.obj \
  /FA \
  /Fa$(BUILD)/masm/util.asm



$(BUILD)/obj/vec4.obj : $(SRC)/data/vec4/vec4.cpp
  cl \
  $(SRC)/data/vec4/vec4.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/vec4.obj \
  /FA \
  /Fa$(BUILD)/masm/vec4.asm



$(BUILD)/obj/vec4-32.obj : $(SRC)/data/vec4/vec4-32.cpp
  cl \
  $(SRC)/data/vec4/vec4-32.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/vec4-32.obj \
  /FA \
  /Fa$(BUILD)/masm/vec4-32.asm



$(BUILD)/obj/vec4-128.obj : $(SRC)/data/vec4/vec4-128.cpp
  cl \
  $(SRC)/data/vec4/vec4-128.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/vec4-128.obj \
  /FA \
  /Fa$(BUILD)/masm/vec4-128.asm



$(BUILD)/obj/quat.obj : $(SRC)/data/quat/quat.cpp
  cl \
  $(SRC)/data/quat/quat.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/quat.obj \
  /FA \
  /Fa$(BUILD)/masm/quat.asm



$(BUILD)/obj/quat-32.obj : $(SRC)/data/quat/quat-32.cpp
  cl \
  $(SRC)/data/quat/quat-32.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/quat-32.obj \
  /FA \
  /Fa$(BUILD)/masm/quat-32.asm



$(BUILD)/obj/quat-128.obj : $(SRC)/data/quat/quat-128.cpp
  cl \
  $(SRC)/data/quat/quat-128.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/quat-128.obj \
  /FA \
  /Fa$(BUILD)/masm/quat-128.asm



$(BUILD)/obj/mat4.obj : $(SRC)/data/mat4/mat4.cpp
  cl \
  $(SRC)/data/mat4/mat4.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/mat4.obj \
  /FA \
  /Fa$(BUILD)/masm/mat4.asm



$(BUILD)/obj/mat4-32.obj : $(SRC)/data/mat4/mat4-32.cpp
  cl \
  $(SRC)/data/mat4/mat4-32.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/mat4-32.obj \
  /FA \
  /Fa$(BUILD)/masm/mat4-32.asm



$(BUILD)/obj/mat4-128.obj : $(SRC)/data/mat4/mat4-128.cpp
  cl \
  $(SRC)/data/mat4/mat4-128.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/mat4-128.obj \
  /FA \
  /Fa$(BUILD)/masm/mat4-128.asm



$(BUILD)/obj/object.obj : $(SRC)/data/data.h $(SRC)/object/object.h $(SRC)/object/object.cpp
  cl \
  $(SRC)/object/object.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/object.obj \
  /FA \
  /Fa$(BUILD)/masm/object.asm



$(BUILD)/obj/time.obj : $(SRC)/time/time.h $(SRC)/time/time.cpp
  cl \
  $(SRC)/time/time.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/time.obj \
  /FA \
  /Fa$(BUILD)/masm/time.asm



$(BUILD)/obj/orbit.obj : $(SRC)/object/object.h $(SRC)/orbit/orbit.h $(SRC)/orbit/orbit.cpp
  cl \
  $(SRC)/orbit/orbit.cpp \
  $(COMP_ARGS) \
  /Fo$(BUILD)/obj/orbit.obj \
  /FA \
  /Fa$(BUILD)/masm/orbit.asm
