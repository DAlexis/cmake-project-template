cmake_minimum_required(VERSION 2.8)

project(program)

find_package (Boost COMPONENTS date_time program_options REQUIRED)

set(EXE_SOURCES
    main.cpp
)

include_directories(
    ${example-lib_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    ${example-lib_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY} # For command line options parsing for example
)

