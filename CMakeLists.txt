cmake_minimum_required(VERSION 3.16)
project(csv_cat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(extern/csv-lib)

add_executable(csv_cat src/main.cpp src/format.h src/format.cpp)
target_link_libraries(csv_cat PUBLIC csv_lib::csv_lib)