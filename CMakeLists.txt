cmake_minimum_required(VERSION 3.4.0)

project(mathx CXX)

# Force out-of-tree builds
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

# Include header files
include_directories(mathx)

# Add appropriate C++ flags
set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++17")

add_subdirectory(src)

# Install library headers
file(GLOB HEADERS mathx/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
install(FILES mathx.h DESTINATION include)
