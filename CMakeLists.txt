cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 64位
if (CMAKE_CL_64)
    # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/debug64)
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/release64)

    # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/lib/debug64)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/lib/release64)

    # 设置头文件的输出目录
    set(publish_include 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/include)

	set(PROJECT_NAME 				${PROJECT_NAME}64)
# 32
else()
    # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/bin/debug)
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/bin/release)

    # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/lib/debug)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/lib/release)

    # 设置头文件的输出目录
    set(publish_include 			${CMAKE_CURRENT_SOURCE_DIR}/publish/x86/include)
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(PROJECT_NAME 				${PROJECT_NAME}64)

# 设置 可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG        ${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/debug64)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 		${CMAKE_CURRENT_SOURCE_DIR}/publish/x64/bin/release64)

# 指定 库文件输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG 	${publish_lib_debug})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RLEASE 	${publish_lib_release})

# Add subdirectories for each module
add_subdirectory(HowTo)
add_subdirectory(Interface)
add_subdirectory(Main)
