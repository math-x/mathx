cmake_minimum_required(VERSION 3.4.0)

project(mathx CXX)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(mathx)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS mathx/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
