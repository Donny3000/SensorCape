cmake_minimum_required(VERSION 2.8)
project(mpu9150)

include_directories(${Common_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED
    src/mpu9150.cpp  
)
target_link_libraries(${PROJECT_NAME} ${Common_LIBRARIES})
add_dependencies(${PROJECT_NAME} Common)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Expose Commons's public includes (including Boost transitively) to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
