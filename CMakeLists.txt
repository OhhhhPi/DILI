cmake_minimum_required(VERSION 3.12)
project(DILI)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-DDEBUG)
endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "/O2 /arch:AVX2 /W1 /EHsc")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    set(CMAKE_CXX_FLAGS "-O3 -xHost")
else()
    # clang and gcc
    #    set(CMAKE_CXX_FLAGS "-lpthread -mpopcnt -O3 -march=native -Wextra -mlzcnt -mcmodel=large -fpermissive")
    set(CMAKE_CXX_FLAGS "-lpthread -mpopcnt -O3 -march=native -mlzcnt -mcmodel=large -fpermissive")
endif()

add_subdirectory(src/global)
add_subdirectory(src/utils)
add_subdirectory(src/dili)

add_subdirectory(src/butree)

include_directories(src/global)
include_directories(src/utils)
include_directories(src/butree)
include_directories(src/dili)


add_executable(dili_lookup_throughput ../../../dili_lookup_throughput.cpp)

target_link_libraries(dili_lookup_throughput dili_func)
target_link_libraries(dili_lookup_throughput butree_func)
target_link_libraries(dili_lookup_throughput global_func)
target_link_libraries(dili_lookup_throughput utils_func)

add_executable(dili_insert_throughput ../../../dili_insert_throughput.cpp)

target_link_libraries(dili_insert_throughput dili_func)
target_link_libraries(dili_insert_throughput butree_func)
target_link_libraries(dili_insert_throughput global_func)
target_link_libraries(dili_insert_throughput utils_func)