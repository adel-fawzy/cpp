add_library(ActiveObject STATIC
    src/ActiveObject.cpp
    src/EventQueue.cpp
)

target_include_directories(ActiveObject PUBLIC
    include
)

target_include_directories(ActiveObject PRIVATE
    src/include
)

find_package(Threads REQUIRED)

target_link_libraries(ActiveObject PRIVATE
    Threads::Threads
)

add_executable(test src/main.cpp)

target_link_libraries(test PRIVATE
    ActiveObject
)