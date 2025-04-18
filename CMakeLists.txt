cmake_minimum_required(VERSION 3.29)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

project(CppModule CXX)

file(GLOB_RECURSE SOURCE_FILES src/**.cpp)
file(GLOB_RECURSE MODULE_FILES src/**.cppm)

add_library(HelloLib)

target_compile_features(HelloLib
        PRIVATE cxx_std_23
        PUBLIC cxx_std_20)

target_sources(HelloLib
        PUBLIC
        ${SOURCE_FILES}
)

target_sources(HelloLib
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        ${MODULE_FILES}
)
if (MINGW)
    target_link_libraries(HelloLib stdc++exp)
endif (MINGW)

add_subdirectory(examples/hello-app)