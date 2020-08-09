cmake_minimum_required(VERSION 3.0.0)
project(mydictionary VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_subdirectory(Request)
add_executable(mydictionary main.cpp)

target_link_libraries(mydictionary PUBLIC Request)
target_link_libraries(mydictionary PUBLIC pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_include_directories(mydictionary PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Request"
                          )
