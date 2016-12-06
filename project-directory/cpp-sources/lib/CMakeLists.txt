cmake_minimum_required(VERSION 2.8)

project(example-lib)

set(LIB_SOURCE
    libsource.cpp
)

set(${PROJECT_NAME}_USED_INCDIRS
    # Add here includes used by library
)

include_directories(${${PROJECT_NAME}_USED_INCDIRS})

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCE})


# This is a way to tell that we need C++11 standart
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_rvalue_references)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_lambdas)

# This is another way. But it will not produce any warnings when 
# compiler does not support it. See below...
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# This tell than C++ standard must be supported
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

export_include_dirs(
    ${PROJECT_SOURCE_DIR}
    ${${PROJECT_NAME}_USED_INCDIRS}
    # Add here include directories that should be exported, i.e. ${PROJECT_SOURCE_DIR}/include
)

export_libs(
    ${PROJECT_NAME}
    # Add here libraries this one depends from
)
