cmake_minimum_required(VERSION 3.23)

project(Tetris)

# Add the executable
add_executable(tetris src/main.cpp)

# Find the SFML package
find_package(SFML)

# Link the SFML libraries
target_link_libraries(tetris PRIVATE sfml-system sfml-window sfml-graphics)
