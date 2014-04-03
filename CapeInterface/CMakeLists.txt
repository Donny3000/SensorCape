cmake_minimum_required(VERSION 2.8)
project(CapeInterface)

# Expose Peripheral's public includes (including Boost transitively) to other
# subprojects through cache variable.
set(ROOT_BIN_DIR ${PROJECT_SOURCE_DIR}/bin
	CACHE INTERNAL "${PROJECT_NAME}: Project Executables Directory" FORCE)
set(ROOT_INC_DIR ${PROJECT_SOURCE_DIR}/bin
	CACHE INTERNAL "${PROJECT_NAME}: Project Includes Directory" FORCE)
set(ROOT_LIB_DIR ${PROJECT_SOURCE_DIR}/bin
	CACHE INTERNAL "${PROJECT_NAME}: Project Libraries Directory" FORCE)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
