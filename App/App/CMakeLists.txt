# CMakeList.txt: CMake project for the App component, include source and define
# project-specific logic here.
#

# Add source to the executable file of this project.
add_executable (App "App.cpp" "App.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET App PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
