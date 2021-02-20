cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(ShinoTests LANGUAGES CXX)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
        NAME Catch2
        GIT_REPOSITORY https://github.com.cnpmjs.org/catchorg/Catch2
        VERSION 2.13.4
)

CPMAddPackage(NAME Shino SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

CPMAddPackage(
  NAME Format.cmake
  GIT_REPOSITORY https://github.com.cnpmjs.org/TheLartians/Format.cmake
  VERSION 1.6
  OPTIONS # enable cmake formatting
          "FORMAT_CHECK_CMAKE ON"
)

# ---- Create binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(ShinoTests ${sources})
target_link_libraries(ShinoTests Catch2 Shino)
set_target_properties(ShinoTests PROPERTIES CXX_STANDARD 17)

# enable compiler warnings
if(NOT TEST_INSTALLED_VERSION)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(Shino PUBLIC -Wall -Wpedantic -Wextra -Werror)
  elseif(MSVC)
    target_compile_options(Shino PUBLIC /W4 /WX)
    target_compile_definitions(ShinoTests PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
endif()

# ---- Add ShinoTests ----

enable_testing()

# Note: doctest and similar testing frameworks can automatically configure CMake tests. For other
# testing frameworks add the tests target instead: add_test(NAME ShinoTests COMMAND ShinoTests)

add_test(ShinoTests ShinoTests)

# ---- code coverage ----

if(ENABLE_TEST_COVERAGE)
  target_compile_options(Shino PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(Shino PUBLIC -fprofile-arcs -ftest-coverage)
endif()

