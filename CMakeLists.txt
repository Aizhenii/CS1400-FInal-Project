cmake_minimum_required(VERSION 3.10)
project(finalproject VERSION 0.1.0 LANGUAGES C CXX)

set(SDL2_INCLUDE_DIR "/opt/homebrew/include/SDL2")
set(SDL2_LIBRARY "/opt/homebrew/lib/libSDL2.dylib")

find_package(SDL2 REQUIRED)

add_executable(finalproject src/main.cpp)

# Link SDL2
target_include_directories(finalproject PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(finalproject PRIVATE ${SDL2_LIBRARIES})

include(CTest)
enable_testing()

