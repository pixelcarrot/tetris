cmake_minimum_required(VERSION 3.23)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(tetris
    src/Board.cpp
    src/Board.hpp
    src/Constant.cpp
    src/Constant.hpp
    src/ControlScreen.hpp
    src/ExitScreen.hpp
    src/FontManager.cpp
    src/FontManager.hpp
    src/GameScreen.cpp
    src/GameScreen.hpp
    src/ImageManager.cpp
    src/ImageManager.hpp
    src/ImageRect.cpp
    src/ImageRect.hpp
    src/Main.cpp
    src/MainScreen.hpp
    src/MenuScreen.cpp
    src/MenuScreen.hpp
    src/PauseScreen.hpp
    src/Piece.cpp
    src/Piece.hpp
    src/ResourceManager.hpp
    src/ScoreScreen.cpp
    src/ScoreScreen.hpp
    src/Screen.hpp
    src/Setting.hpp
    src/SoundBufferManager.cpp
    src/SoundBufferManager.hpp
    src/StringUtility.cpp
    src/StringUtility.hpp
)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Link the SFML libraries
target_link_libraries(tetris sfml-graphics sfml-audio)

# Custom command to copy the entire data directory to the build output
set(TARGET_NAME tetris)
set(DATA_SOURCE_DIR "${CMAKE_SOURCE_DIR}/data")
set(DATA_DEST_DIR "${CMAKE_BINARY_DIR}/data")

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${DATA_SOURCE_DIR} ${DATA_DEST_DIR}
    COMMENT "Copying data directory to build output"
)

# Ensure the destination directory exists
file(MAKE_DIRECTORY ${DATA_DEST_DIR})
