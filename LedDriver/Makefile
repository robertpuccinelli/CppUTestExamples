SILENCE = @

COMPONENT_NAME = LedDriver

CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .
#CPPUTEST_HOME = $(CPPUTEST_HOME)

INCLUDE_DIRS = $(PROJECT_HOME_DIR)/lib \
							 $(PROJECT_HOME_DIR)/mocks
SRC_DIRS = $(PROJECT_HOME_DIR)/src \
					 $(PROJECT_HOME_DIR)/mocks
TEST_SRC_DIRS = $(PROJECT_HOME_DIR)/tests \
MOCKS_DIRS =

CPPFLAGS += -I$(CPPUTEST_HOME)/include -I$(CPPUTEST_HOME)/mocks
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default
#-Werror #Causes failures on unused parameters
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
LD_LIBRARIES = -lpthread -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
