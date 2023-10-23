cmake_minimum_required(VERSION 3.24)
project(space_invader_v2)

# Set the C++ standard to 17.
set(CMAKE_CXX_STANDARD 17)

# Create an executable for the project.
add_executable(space_invader_v2 main.cpp player_ship.h player_ship.cpp bullet.h bullet.cpp alien.h alien.cpp game_events.cpp
        game_events.h
        screen_state.cpp
        screen_state.h
        power_ups.cpp
        power_ups.h
) # Replace 'main.cpp' with your source files.

# Set SFML to use static libraries.
set(SFML_STATIC_LIBRARIES TRUE)

# Set the SFML directory appropriately.
set(SFML_DIR "C:/SFML/SFML-2.6.0/lib/cmake/SFML")

# Find the SFML package.
find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

# Include SFML directories for the project.
include_directories("C:/SFML/SFML-2.6.0/include")

# Link the SFML libraries to the project.
target_link_libraries(space_invader_v2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
