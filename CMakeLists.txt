cmake_minimum_required(VERSION 3.15)

# set the project name
project(PLS)

# add the executable
set(SRC_LIST

	src/input.c
	src/main.c
	src/output.c
	src/runpls.c
	src/tools.c)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
