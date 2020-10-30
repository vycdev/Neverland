cmake_minimum_required(VERSION 3.0)
project(Neverland C)

set(CMAKE_C_STANDARD 99)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(raylib_template src/main.c src/headers/player.h src/components/player.c src/components/camera.c src/headers/camera.h src/headers/debugger.h src/components/debugger.c src/components/playerhud.c src/headers/playerhud.h src/headers/methods.h src/components/methods.c src/components/abilities.c src/headers/abilities.h)
target_link_libraries(raylib_template PRIVATE raylib)
target_compile_definitions(raylib_template PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(raylib_template PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
