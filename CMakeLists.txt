
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(pong)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Manually find SDL2_image and SDL2_mixer
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2_IMAGE REQUIRED sdl2_image)
pkg_check_modules(SDL2_MIXER REQUIRED sdl2_mixer)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_IMAGE_LIBRARY_DIRS} ${SDL2_MIXER_LIBRARY_DIRS})

# Add the executable
set(SOURCES
    src/main.cpp
    src/pong.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

