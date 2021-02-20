cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# ---- Project ----

# Note: update this to your new project's name and version
project(
        Shino
        VERSION 1.0
        LANGUAGES CXX
)

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
            FATAL_ERROR
            "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info

include(cmake/CPM.cmake)

CPMAddPackage(
        NAME spdlog
        GIT_REPOSITORY https://github.com.cnpmjs.org/gabime/spdlog
        VERSION 1.8.2
)

CPMAddPackage(
        NAME fmt
        GIT_TAG 6.1.2
        GIT_REPOSITORY https://github.com.cnpmjs.org/fmtlib/fmt
)

# ---- Add source files ----

# Note: globbing sources is considered bad practice as CMake's generators may not detect new files
# automatically. Keep that in mind when changing files, or explicitly mention them here.
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_library(Shino ${headers} ${sources})

set_target_properties(Shino PROPERTIES CXX_STANDARD 17)

target_compile_options(Shino PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive>")


# Link dependencies
target_link_libraries(Shino PUBLIC spdlog fmt::fmt)

target_include_directories(
        Shino PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)
