set(SRC_FILES
    src/main.cpp
    src/core/App.cpp
    src/core/Display.cpp
    src/core/Mobile.cpp
    src/core/WeatherStation.cpp
    src/utils/Logger.cpp
)

find_package(Threads REQUIRED)

add_executable(observer-mediator ${SRC_FILES})

target_link_libraries(observer-mediator PRIVATE Threads::Threads)

target_include_directories(observer-mediator PRIVATE
    src/include
)

target_link_libraries(observer-mediator PRIVATE
    ActiveObject
)