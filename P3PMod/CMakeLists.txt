cmake_minimum_required(VERSION 3.18)

set(TARGET P3PMod)
project(${TARGET})

add_library(${TARGET} SHARED Private/main.cpp)
target_include_directories(${TARGET} PRIVATE Public/)

target_link_libraries(${TARGET} PRIVATE UE4SS)
