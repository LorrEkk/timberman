cmake_minimum_required(VERSION 3.24)
project(timberman)

set(CMAKE_CXX_STANDARD 23)

add_executable(timberman main.cpp tree.cpp tree.h display.cpp display.h reader.h readerKeyboard.cpp readerKeyboard.h readerMouse.cpp readerMouse.h engine.cpp engine.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR ./lib/SFML/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML COMPONENTS system  window graphics REQUIRED)

include_directories(./lib/SFML/SFML-2.5.1/include)
target_link_libraries(timberman sfml-system sfml-window sfml-graphics)
