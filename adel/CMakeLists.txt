cmake_minimum_required(VERSION 3.16)

project(adel LANGUAGES CXX)

# Create lib
add_library(${PROJECT_NAME} SHARED
    src/core/ActiveObject.cpp
    src/core/EventQueue.cpp
)

set(CMAKE_INSTALL_PREFIX /usr)

target_include_directories(${PROJECT_NAME} PUBLIC
    include/
)

# Private headers
target_include_directories(${PROJECT_NAME} PRIVATE
    src/include
)

# Install lib headers
install(DIRECTORY include/
    DESTINATION include/adel
)

# Install lib
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
)

# Link with threads of C++ standard lib
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Threads::Threads
)