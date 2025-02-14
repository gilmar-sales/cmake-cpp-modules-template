cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

project(CppModule CXX)

file(GLOB_RECURSE SOURCE_FILES src/**.cpp)
file(GLOB_RECURSE MODULE_FILES src/**.cppm)

add_executable(Main)

target_compile_features(Main
        PRIVATE cxx_std_23
        PUBLIC cxx_std_20)

target_sources(Main
        PUBLIC
        ${SOURCE_FILES}
)

target_sources(Main
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        ${MODULE_FILES}
)
