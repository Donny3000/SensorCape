cmake_minimum_required(VERSION 2.8)
project(Common)                

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED
	src/I2CInterface.cpp
	src/SignalHandler.cpp
)
  
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
  
# Expose Commons's public includes (including Boost transitively) to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
