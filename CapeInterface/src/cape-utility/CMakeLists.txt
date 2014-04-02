cmake_minimum_required(VERSION 2.8)
project(cape-utility)

include_directories(${Common_INCLUDE_DIRS})
include_directories(${mpu9150_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories()

add_executable(${PROJECT_NAME}
	src/main.cpp
)
target_link_libraries(${PROJECT_NAME} Common mpu9150)
add_dependencies(${PROJECT_NAME} Common mpu9150)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
