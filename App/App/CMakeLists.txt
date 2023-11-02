# CMakeList.txt: CMake project for the App component, include source and define
# project-specific logic here.
#

# Add source to the executable file of this project.
add_executable (App "main.cpp" "main.h" "user_interface.h" "user_interface.cpp" "Methods/add_person.cpp" "Methods/edit_data.cpp" "Methods/add_person.h" "Methods/edit_data.h" "Methods/manage_interests.cpp" "Methods/manage_interests.h" "Methods/group_people.h" "Methods/group_people.cpp" "Database/read.cpp" "Database/read.h" "Database/write.cpp" "Database/write.h" "Methods/import_export.cpp" "Methods/import_export.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET App PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
