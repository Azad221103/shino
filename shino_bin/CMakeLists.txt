cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(ShinoBin LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)


CPMAddPackage(NAME Shino SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

add_executable(ShinoBin ${sources})

set_target_properties(ShinoBin PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "Shino")

target_link_libraries(ShinoBin Shino)
