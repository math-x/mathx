cmake_minimum_required(VERSION 3.4.0)

project(mathx CXX)

# Include header files
include_directories(mathx)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include(mathx_GeneratePackage)

# add_subdirectory(src)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Install library headers
file(GLOB HEADERS mathx/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
install(FILES mathx.h DESTINATION include)
