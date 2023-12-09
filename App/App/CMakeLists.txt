# CMake project for the App component
# Include source and define project-specific logic here.

cmake_minimum_required(VERSION 3.12)

project(App)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to the executable file of this project.
file(GLOB SOURCES "main.cpp" "user_interface.cpp" "config/*.cpp" "Methods/*.cpp" "Database/*.cpp" "Methods/Edits_Methods/*.cpp" "Methods/Display_Methods/*.cpp")
file(GLOB HEADERS "*.h" "Methods/*.h" "Database/*.h" "config/*.h" "Methods/Edits_Methods/*.h" "Methods/Display_Methods/*.h")

add_executable(App ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(App PRIVATE Methods Database)

# Set compiler features
target_compile_features(App PRIVATE cxx_std_20)
