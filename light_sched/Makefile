CLEANUP = rm -f
MKDIR   = mkdir -p
TARGET_EXTENSION = .out

HOST_CXX = g++
HOST_CC  = gcc

CXXFLAGS = -Wall -Wextra -std=c++11
CFLAGS   = -Wall -Wextra -std=c99

TEST_BUILD_FOLDER = build/Testing
TARGET_BASE1      = all_tests

TEST_ROOT        = Utest
HOME_AUT_ROOT    = src/home_automation
UNIT_TESTS_ROOT  = Utest/tests/home_automation_tests

TARGET1 = $(TEST_BUILD_FOLDER)/$(TARGET_BASE1)$(TARGET_EXTENSION)

# --- Sources ---
SRC_C   = $(HOME_AUT_ROOT)/home_aut.c
SRC_CPP = $(TEST_ROOT)/all_tests.cpp \
          $(UNIT_TESTS_ROOT)/home_aut_test.cpp

# --- Objects ---
OBJ_C   = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)
OBJS    = $(OBJ_C) $(OBJ_CPP)

# Include directories (directories, not files)
INC_DIRS = \
	-I$(HOME_AUT_ROOT) \
	-I$(TEST_ROOT) \
	-I$(UNIT_TESTS_ROOT)

all: $(TARGET1)
	- ./$(TARGET1)

$(TARGET1): $(OBJS)
	$(MKDIR) $(TEST_BUILD_FOLDER)
	$(HOST_CXX) $(CXXFLAGS) $(INC_DIRS) $^ -lCppUTest -lCppUTestExt -o $@

# Compile C as C
%.o: %.c
	$(HOST_CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Compile C++ as C++
%.o: %.cpp
	$(HOST_CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	$(CLEANUP) $(OBJS) $(TARGET1)

ci: CFLAGS += -Werror
ci: all
