cmake_minimum_required(VERSION 3.10)

project(Interface)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost library
#find_package(Boost 1.82.0 REQUIRED COMPONENTS system)

# 将需要输出的头文件放在输出目录下
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
foreach(HEADER_FILE ${HEADER_FILES})
    file(COPY ${HEADER_FILE} DESTINATION ${publish_include})
endforeach()

# 设置头文件路径
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# Add Source
set(SOURCE
# .cpp
#src/CATMathPoint.cpp
src/SJDBuildCatalogCls.cpp
src/ZWReadTreeDataCls.cpp
)


# Add library
add_library(Interface SHARED ${SOURCE})

# Install library
install(TARGETS Interface DESTINATION lib)

