cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    ${publish_include}
)

# 设置链接库路径
link_directories(
    $ENV{HowTo_ROOT}/lib
)

# Add executable
add_executable(MyExecutable main.cpp)

# Link HowTo, Interface, and Service libraries
target_link_libraries(MyExecutable PRIVATE HowTo)