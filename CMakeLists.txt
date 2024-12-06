set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.10)
project(finalproject VERSION 0.1.0 LANGUAGES C CXX)

set(SDL2_INCLUDE_DIR "/opt/homebrew/include/SDL2")
set(SDL2_LIBRARY "/opt/homebrew/lib/libSDL2.dylib")

find_package(SDL2 REQUIRED)

# Automatically find all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Create the executable from the found files
add_executable(finalproject ${SRC_FILES})

# Link SDL2
target_include_directories(finalproject PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(finalproject PRIVATE ${SDL2_LIBRARIES})

include(CTest)
enable_testing()

