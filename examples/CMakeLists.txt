project(Examples)

add_executable(simple_window simple_window.cpp)
target_include_directories(simple_window PRIVATE "${CMAKE_SOURCE_DIR}/src/public")
target_link_libraries(simple_window PRIVATE Eclipse)
