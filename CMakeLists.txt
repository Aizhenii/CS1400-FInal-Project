set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.10)
project(finalproject VERSION 0.1.0 LANGUAGES C CXX)

# Set SDL2 and SDL2_ttf paths
if(WIN32)
    # SDL2 paths for Windows
    set(SDL2_INCLUDE_DIR "C:/libs/SDL2/include" CACHE PATH "Set path to SDL2 include directory (e.g., C:/libs/SDL2/include)")
    set(SDL2_LIBRARY "C:/libs/SDL2/lib/x64/SDL2.lib" CACHE FILEPATH "Set path to SDL2 library (e.g., C:/libs/SDL2/lib/x64/SDL2.lib)")

    if(NOT SDL2_INCLUDE_DIR)
        message(FATAL_ERROR "You haven't set a path to the SDL2 include directory.")
    endif()

    if(NOT SDL2_LIBRARY)
        message(FATAL_ERROR "You haven't set a path to the SDL2 library.")
    endif()

    # Automatically find all .cpp files in the src directory
    file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

    # Create the executable
    add_executable(finalproject ${SRC_FILES})

    # Include SDL2 directories and link libraries
    target_include_directories(finalproject PRIVATE ${SDL2_INCLUDE_DIR})
    target_link_libraries(finalproject PRIVATE ${SDL2_LIBRARY})

elseif(APPLE)
    find_package(SDL2 REQUIRED)

    # Automatically find all .cpp files in the src directory
    file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

    # Create the executable
    add_executable(finalproject ${SRC_FILES})

    # Include SDL2 directories and link libraries
    target_include_directories(finalproject PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(finalproject PRIVATE ${SDL2_LIBRARIES})

else()
    message(FATAL_ERROR "This project only supports Windows and macOS.")
endif()

include(CTest)
enable_testing()

