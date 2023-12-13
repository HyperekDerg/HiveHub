# CMake project for the App component
# Include source and define project-specific logic here.

cmake_minimum_required(VERSION 3.8)

project(HiveHub)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to the executable file of this project.
file(GLOB_RECURSE SOURCES "main.cpp" "Config/*.cpp" "Database/*.cpp" "Methods/*.cpp" "Methods/Edits_Features/*.cpp" "Methods/User_Display_Features/*.cpp" "Methods/GUI_Features/*.cpp")
file(GLOB_RECURSE HEADERS "*.h"  "Config/*.h" "Database/*.h" "Methods/*.h" "Methods/User_Display_Features/*.h" "Methods/GUI_Features/*.h")

add_executable(HiveHub ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(HiveHub PRIVATE Methods Database Config)

# Set compiler features
target_compile_features(HiveHub PRIVATE cxx_std_20)
