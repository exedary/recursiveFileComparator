cmake_minimum_required(VERSION 3.13)
project(NPOWORLDTESTTASK)

set(CMAKE_CXX_STANDARD 17)

set(FS "-lstdc++fs")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${FS}")
add_executable(NPOWORLDTESTTASK src/main.cpp src/PathReader.cpp src/PathReader.h src/useless/FilePathReader.cpp src/useless/FilePathReader.h)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
target_link_libraries(${PROJECT_NAME} stdc++fs)
add_compile_options(/std:c++latest)
