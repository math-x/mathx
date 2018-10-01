# Find source files
file(GLOB SOURCES ./*.cpp)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})