cmake_minimum_required(VERSION 3.12...3.21)

project(customFormat VERSION 0.1 LANGUAGES CXX)

add_executable(customFormat
			   ./include/key.hpp
			   ./include/token.hpp
			   ./include/parser.hpp
			   ./src/key.cpp
			   ./src/token.cpp
			   ./src/parser.cpp
			   ./src/main.cpp)
target_include_directories(customFormat PRIVATE include)

target_compile_features(customFormat PRIVATE cxx_std_20)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_options(customFormat PRIVATE /W4)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_options(customFormat PRIVATE -Wall -Wextra -Wpedantic -Wno-unknown-pragmas)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_options(customFormat PRIVATE)
endif()



