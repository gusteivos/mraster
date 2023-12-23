
cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(mraster VERSION 0.0.0.1 LANGUAGES C)


file(GLOB executable_source_files
    "./*.c"
    "./vectors/*.c"
)

set(executable_header_files
    ./
)


find_package(SDL2 REQUIRED)


add_executable(${CMAKE_PROJECT_NAME} ${executable_source_files})

include_directories(${executable_header_files})


if(CMAKE_BUILD_TYPE STREQUAL "Debug")

    target_link_libraries(${CMAKE_PROJECT_NAME} SDL2)

else()

    include_directories(${SDL2_INCLUDE_DIRS})

    target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})

endif()


target_link_libraries(${CMAKE_PROJECT_NAME} m)
