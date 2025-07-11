
CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out


C_COMPILER=gcc

UNITY_ROOT=Unity

CFLAGS=-std=c99
#CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TEST_BUILD_FODLER=build/Testing
TARGET_BASE1=all_tests
TARGET1 = $(TEST_BUILD_FODLER)/$(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  src/main.c \
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/LED_Driver.c \
  src/Circular_Buffer.c \
  Unit_tests/LED_Driver_TEST.c \
  Unit_tests/Circular_Buffer_TEST.c \
  Unit_tests/Test_Runners/LED_Driver_TEST_RUNNER.c \
  Unit_tests/Test_Runners/Circular_Buffer_TEST_RUNNER.c \
  Unit_tests/Test_Runners/run_all.c \
  

INC_DIRS=-Iinc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=-DUNITY_FIXTURE_NO_EXTRAS

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1) -v

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default
