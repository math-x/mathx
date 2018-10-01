cmake_minimum_required(VERSION 3.4.0)

project(mathx CXX)

# Include header files
include_directories(mathx)

add_subdirectory(src)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

# Install library headers
file(GLOB HEADERS mathx/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
install(FILES mathx.h DESTINATION include)
