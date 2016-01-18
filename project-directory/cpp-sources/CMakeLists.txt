cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project("Project-name")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -pg -D_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -g -DNDEBUG")

# For using define GIT_COMMIT_TAG in code
execute_process(COMMAND git log -1 --format="%H" OUTPUT_VARIABLE git_commit)
add_definitions( -DGIT_COMMIT_TAG=${git_commit} )

# This is to run all tests using 'make run-unit-tests' command.
# Another way is simply run 'ctest -VV', but output is not colorized :(
add_custom_target(run-unit-tests)
macro(run_test test_target)
  add_custom_target(${test_target}_runtest
      COMMAND ${test_target} #cmake 2.6 required
      DEPENDS ${test_target}
      WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
  add_dependencies(run-unit-tests ${test_target}_runtest)
endmacro()

# This macro creates variable ${PROJECT_NAME}_INCLUDE_DIRS with list of includes
# given to it
macro(export_include_dirs)
    set(${PROJECT_NAME}_INCLUDE_DIRS
        ${ARGV}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
endmacro()

add_subdirectory(lib)
add_subdirectory(program)

# To enable ctest usage
enable_testing()

add_subdirectory(unit-tests)
