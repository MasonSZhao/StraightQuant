# CMakeList.txt : CMake project for StraightOffice, include source and define project specific logic here.

# Require a minimum version of cmake.
cmake_minimum_required (VERSION 3.21)

# Set the C++ standard.
set(CMAKE_CXX_STANDARD 20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set the name of the project.
project ("StraightQuant")

# Glob all files ended with .h and .cpp in the folders.
file (GLOB STRAIGHTSTOCK_HEADERS CONFIGURE_DEPENDS "include/StraightStock/StraightStock*.h")
file (GLOB STRAIGHTSTOCK_SRCS CONFIGURE_DEPENDS "src/StraightStock/StraightStock*.cpp")

# Add source to the project's executable application.
add_executable (
	StraightQuantExecute
	"apps/StraightQuant.cpp" 
	"apps/StraightQuant.h"
	${STRAIGHTSTOCK_SRCS}
	${STRAIGHTSTOCK_HEADERS}
 )

 # Add source to the project's static library.
 add_library(
	StraightStockStatic
	STATIC
	${STRAIGHTSTOCK_SRCS}
	${STRAIGHTSTOCK_HEADERS}
)

# Add include directories to the project's static library.
target_include_directories(
	StraightStockStatic 
	PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/StraightStock>"	
)

# Test option
set(STRAIGHTQUANT_BUILD_TESTS OFF)

if (STRAIGHTQUANT_BUILD_TESTS)

	# Enable testing for current directory and below.
	enable_testing()

	# Add a subdirectory to the build.
	add_subdirectory("tests")

endif()
