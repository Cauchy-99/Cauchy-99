cmake_minimum_required(VERSION 3.10)

project(HowTo)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost library
#find_package(Boost 1.82.0 REQUIRED COMPONENTS system)

include_directories(
    ${publish_include}
    ${Boost_INCLUDE_DIRS}
)

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
foreach(HEADER_FILE ${HEADER_FILES})
    file(COPY ${HEADER_FILE} DESTINATION ${publish_include})
endforeach()

# Add Source
set(SOURCE
# .h
include/HowTo.h
include/HowToReadText.h
#include/HowToUnique3DPoint.h

# .cpp
src/HowTo.cpp
src/HowToReadText.cpp
#src/HowToUnique3DPoint.cpp
)

# 设置链接库路径
link_directories(
    ${publish_lib_debug}
)


# Add library
add_library(HowTo SHARED ${SOURCE})

# Set library output name
set_target_properties(HowTo PROPERTIES LIBRARY_OUTPUT_DIRECTORY $ENV{HowTo_ROOT}/lib)

target_link_libraries(HowTo PRIVATE Interface)

# Install library
install(TARGETS HowTo DESTINATION lib)