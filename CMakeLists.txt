 cmake_minimum_required(VERSION 3.14)
 project(
         shino
         VERSION 1.0
         LANGUAGES CXX
 )

 add_definitions("-std=c++11")

 include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
 conan_basic_setup()

 file(GLOB_RECURSE SHINO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

 add_executable(shino ${SHINO_SRC})
 target_link_libraries(shino ${CONAN_LIBS})